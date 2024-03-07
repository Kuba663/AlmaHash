// HashFunc.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "HashFunc.h"

/* Type your code here, or load an example. */

#define X22             0x00400000   
#define X11             0x00000800   
#define MASK12          0xfffff800   
#define GENPOL          0x00000c75   

struct sponge_state {
    long encoding_table[4096];
    uint8_t state[672];
};

long
#ifdef _MSC_VER
__forceinline
#else
__attribute__((always_inline)) inline
#endif
get_syndrome(pattern)
long pattern;
{
    long aux = X22, aux2;

    if (pattern >= X11)
        while (pattern & MASK12) {
            while (!(aux & pattern))
                aux = aux >> 1;
            pattern ^= (aux / X11) * GENPOL;
        }
    return(pattern);
}

uint64_t splitmix64(uint64_t* state) {
    uint64_t result = ((*state) += 0x9E3779B97f4A7C15);
    result = (result ^ (result >> 30)) * 0xBF58476D1CE4E5B9;
    result = (result ^ (result >> 27)) * 0x94D049BB133111EB;
    return result ^ (result >> 31);
}
#ifdef _MSC_VER
uint64_t xoshiro256ss(struct xoshiro256ss_state* state)
{
    uint64_t* s = state->s;
    uint64_t const result = _rotl64(s[1] * 5, 7) * 9;
    uint64_t const t = s[1] << 17;

    __m256i vec = _mm256_load_si256((__m256i*)s);
    __m256i tmp = _mm256_set_epi64x(s[3], s[2], s[1], s[0]);
    const __m256i mask = _mm256_set1_epi64x(-1);
    vec = _mm256_xor_si256(vec, tmp);
    _mm256_maskstore_epi64(s, mask, vec);

    s[2] ^= t;
    s[3] = _rotl64(s[3], 45);

    return result;
}
#else
#define rol(x,y) asm volatile ("rol {%0,%1|%1,%0}" : : "r" (x), "r" (y) : "cc")

uint64_t xoshiro256ss(struct xoshiro256ss_state* state)
{
    uint64_t* s = state->s;
    uint64_t tr = s[1] * 5;
    rol(tr, 7);
    uint64_t const result = tr * 9;
    uint64_t const t = s[1] << 17;

    __m256i vec = _mm256_load_si256((__m256i*)s);
    __m256i tmp = _mm256_set_epi64x(s[3], s[2], s[1], s[0]);
    const __m256i mask = _mm256_set1_epi64x(-1);
    vec = _mm256_xor_si256(vec, tmp);
    _mm256_maskstore_epi64((long long*)s, mask, vec);

    s[2] ^= t;
    rol(s[3], 45);

    return result;
}
#endif

void compress(uint8_t G[8], uint8_t H[8], uint8_t m[16]) {
#ifdef _MSC_VER
    uint8_t _declspec(align(16)) key[24];
    uint8_t _declspec(align(16)) ex[24 * 13];
#else
    uint8_t ex[24 * 13] __attribute__((aligned(16)));
    uint8_t key[24] __attribute__((aligned(16)));
#endif
    memcpy(key, H, 8);
    memcpy(&key[8], m, 16);
    uint8_t gc[8];
    for (int i = 0; i < 8; i++) gc[i] = G[i] ^ 163;
    expand(key, ex);
    uint8_t tmp1[8], tmp2[8];
    cipher(gc, ex, tmp1);
    cipher(G, ex, tmp2);
    for (int i = 0; i < 8; i++) {
        H = tmp1[i] ^ gc[i];
        G = tmp2[i] ^ G[i];
    }
}

void absorb(struct sponge_state* state, uint8_t b[63]) {
    for (int i = 0; i < 63; i++) state->state[i] ^= b[i];

}

void init_sponge(struct sponge_state* state) {
    long pattern;
    long temp;
    for (pattern = 0; pattern < 4096; pattern++) {
        temp = pattern << 11;
        state->encoding_table[pattern] = temp + get_syndrome(temp);
    }

}
