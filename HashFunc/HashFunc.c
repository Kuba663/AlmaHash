// HashFunc.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "HashFunc.h"


uint64_t volatile splitmix64(uint64_t* state) {
    uint64_t result = ((*state) += 0x9E3779B97f4A7C15);
    result = (result ^ (result >> 30)) * 0xBF58476D1CE4E5B9;
    result = (result ^ (result >> 27)) * 0x94D049BB133111EB;
    return result ^ (result >> 31);
}
#ifdef _MSC_VER
uint64_t volatile xoshiro256ss(struct xoshiro256ss_state* state)
{
    uint64_t* s = state->s;
    uint64_t const result = _rotl64(s[1] * 5, 7) * 9;
    uint64_t const t = s[1] << 17;

    __m256i vec = _mm256_loadu_si256((__m256i*)s);
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

uint64_t volatile xoshiro256ss(struct xoshiro256ss_state* state)
{
    uint64_t* s = state->s;
    uint64_t tr = s[1] * 5;
    rol(tr, 7);
    uint64_t const result = tr * 9;
    uint64_t const t = s[1] << 17;

    __m256i vec = _mm256_loadu_si256((__m256i*)s);
    __m256i tmp = _mm256_set_epi64x(s[3], s[2], s[1], s[0]);
    const __m256i mask = _mm256_set1_epi64x(-1);
    vec = _mm256_xor_si256(vec, tmp);
    _mm256_maskstore_epi64((long long*)s, mask, vec);

    s[2] ^= t;
    rol(s[3], 45);

    return result;
}
#endif

#define to64b(arr) (((uint64_t)(((uint8_t *)(arr))[7]) <<  0)+ ((uint64_t)(((uint8_t*)(arr))[6]) << 8) + ((uint64_t)(((uint8_t*)(arr))[5]) << 16) + ((uint64_t)(((uint8_t*)(arr))[4]) << 24) + ((uint64_t)(((uint8_t*)(arr))[3]) << 32) + ((uint64_t)(((uint8_t*)(arr))[2]) << 40) + ((uint64_t)(((uint8_t*)(arr))[1]) << 48) + ((uint64_t)(((uint8_t*)(arr))[0]) << 56))

void volatile compress(uint8_t G[8], uint8_t H[8], uint8_t m[16]) {
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
    uint64_t splitmixState = (to64b(G)) ^ 163;
    struct xoshiro256ss_state rng;
    for (int i = 0; i < 4; i++) rng.s[i] = splitmix64(&splitmixState);
    uint64_t tmp = xoshiro256ss(&rng);
    for (int i = 0; i < 8; i++) gc[i] = tmp >> i * 8;
    expand(key, ex);
    uint8_t tmp1[8], tmp2[8];
    cipher(gc, ex, tmp1);
    cipher(G, ex, tmp2);
    for (int i = 0; i < 8; i++) {
        H[i] = tmp1[i] ^ gc[i];
        G[i] = tmp2[i] ^ G[i];
    }
}

void volatile ALMA_API init_sponge(struct sponge_state* state, uint8_t* key, size_t keySize) {
    state->squeezeIndex = 0;
    uint64_t splitmix_state = 0;
    for (size_t i = 0; i < keySize - (keySize % 8); i += 8) splitmix_state ^= to64b(&key[i]);
    for (int i = 0; i < 4; i++) state->keygen.s[i] = splitmix64(&splitmix_state);
}

void volatile ALMA_API absorb(struct sponge_state* state, uint8_t b[63]) {
    for (int i = 0; i < 63; i++) state->state[0][i] ^= b[i];
    for (int i = 0; i < 672; i += 8) {
        uint8_t key[16];
        uint64_t tmp[2] = { xoshiro256ss(&state->keygen), xoshiro256ss(&state->keygen) };
        for (int i = 0; i < 8; i++) key[i] = tmp[0] >> i * 8;
        for (int i = 0; i < 8; i++) key[8+i] = tmp[1] >> i * 8;
        compress(&state->state[1][i], &state->state[0][i], key);
    }
}

uint8_t volatile ALMA_API squeeze(struct sponge_state* state) {
    uint8_t b = state->state[0][state->squeezeIndex];
    state->squeezeIndex++;
    state->squeezeIndex %= 63;
    for (int i = 0; i < 672; i += 8) {
        uint8_t key[16];
        uint64_t tmp[2] = { xoshiro256ss(&state->keygen), xoshiro256ss(&state->keygen) };
        for (int i = 0; i < 8; i++) key[i] = tmp[0] >> i * 8;
        for (int i = 0; i < 8; i++) key[8 + i] = tmp[1] >> i * 8;
        compress(&state->state[1][i], &state->state[0][i], key);
    }
    return b;
}
