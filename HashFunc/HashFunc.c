// HashFunc.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "HashFunc.h"

const uint64_t primes[16] = { 18446744073709551557, 18446744073709551533, 18446744073709551521, 18446744073709539689, 18446744073709092289, 18446744073708649133,
17999999999999999921, 1799999939999999897, 17999999398899999863, 8191, 163, 15636566556662663483, 14444444556444444457, 12234324324251, 1223432432432376503, 16666666666666666633 };

const uint8_t smallPrimes[54] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107,
109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179,
181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251 };

const uint8_t rijndael[256] = { 0x63 ,0x7c ,0x77 ,0x7b ,0xf2 ,0x6b ,0x6f ,0xc5 ,0x30 ,0x01 ,0x67 ,0x2b ,0xfe ,0xd7 ,0xab ,0x76
    ,0xca ,0x82 ,0xc9 ,0x7d ,0xfa ,0x59 ,0x47 ,0xf0 ,0xad ,0xd4 ,0xa2 ,0xaf ,0x9c ,0xa4 ,0x72 ,0xc0
     ,0xb7 ,0xfd ,0x93 ,0x26 ,0x36 ,0x3f ,0xf7 ,0xcc ,0x34 ,0xa5 ,0xe5 ,0xf1 ,0x71 ,0xd8 ,0x31 ,0x15
     ,0x04 ,0xc7 ,0x23 ,0xc3 ,0x18 ,0x96 ,0x05 ,0x9a ,0x07 ,0x12 ,0x80 ,0xe2 ,0xeb ,0x27 ,0xb2 ,0x75
     ,0x09 ,0x83 ,0x2c ,0x1a ,0x1b ,0x6e ,0x5a ,0xa0 ,0x52 ,0x3b ,0xd6 ,0xb3 ,0x29 ,0xe3 ,0x2f ,0x84
     ,0x53 ,0xd1 ,0x00 ,0xed ,0x20 ,0xfc ,0xb1 ,0x5b ,0x6a ,0xcb ,0xbe ,0x39 ,0x4a ,0x4c ,0x58 ,0xcf
     ,0xd0 ,0xef ,0xaa ,0xfb ,0x43 ,0x4d ,0x33 ,0x85 ,0x45 ,0xf9 ,0x02 ,0x7f ,0x50 ,0x3c ,0x9f ,0xa8
     ,0x51 ,0xa3 ,0x40 ,0x8f ,0x92 ,0x9d ,0x38 ,0xf5 ,0xbc ,0xb6 ,0xda ,0x21 ,0x10 ,0xff ,0xf3 ,0xd2
     ,0xcd ,0x0c ,0x13 ,0xec ,0x5f ,0x97 ,0x44 ,0x17 ,0xc4 ,0xa7 ,0x7e ,0x3d ,0x64 ,0x5d ,0x19 ,0x73
     ,0x60 ,0x81 ,0x4f ,0xdc ,0x22 ,0x2a ,0x90 ,0x88 ,0x46 ,0xee ,0xb8 ,0x14 ,0xde ,0x5e ,0x0b ,0xdb
     ,0xe0 ,0x32 ,0x3a ,0x0a ,0x49 ,0x06 ,0x24 ,0x5c ,0xc2 ,0xd3 ,0xac ,0x62 ,0x91 ,0x95 ,0xe4 ,0x79
     ,0xe7 ,0xc8 ,0x37 ,0x6d ,0x8d ,0xd5 ,0x4e ,0xa9 ,0x6c ,0x56 ,0xf4 ,0xea ,0x65 ,0x7a ,0xae ,0x08
     ,0xba ,0x78 ,0x25 ,0x2e ,0x1c ,0xa6 ,0xb4 ,0xc6 ,0xe8 ,0xdd ,0x74 ,0x1f ,0x4b ,0xbd ,0x8b ,0x8a
     ,0x70 ,0x3e ,0xb5 ,0x66 ,0x48 ,0x03 ,0xf6 ,0x0e ,0x61 ,0x35 ,0x57 ,0xb9 ,0x86 ,0xc1 ,0x1d ,0x9e
     ,0xe1 ,0xf8 ,0x98 ,0x11 ,0x69 ,0xd9 ,0x8e ,0x94 ,0x9b ,0x1e ,0x87 ,0xe9 ,0xce ,0x55 ,0x28 ,0xdf
     ,0x8c ,0xa1 ,0x89 ,0x0d ,0xbf ,0xe6 ,0x42 ,0x68 ,0x41 ,0x99 ,0x2d ,0x0f ,0xb0 ,0x54 ,0xbb ,0x16 };

#pragma optimize( "s", on )
uint64_t splitmix64(uint64_t* state) {
    uint64_t result = ((*state) += 0x9E3779B97f4A7C15);
    result = (result ^ (result >> 30)) * 0xBF58476D1CE4E5B9;
    result = (result ^ (result >> 27)) * 0x94D049BB133111EB;
    return result ^ (result >> 31);
}
#ifdef _MSC_VER
#include <intrin.h>

#pragma intrinsic(_rotl8, _rotr8, memcpy)

#pragma optimize( "s", on )
uint64_t xoshiro256ss(struct xoshiro256ss_state* state)
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

uint64_t xoshiro256ss(struct xoshiro256ss_state* state)
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

#define to64l(arr) (((uint64_t)(((uint8_t *)(arr))[0]) <<  0)+((uint64_t)(((uint8_t*)(arr))[1]) << 8) + ((uint64_t)(((uint8_t*)(arr))[2]) << 16) + ((uint64_t)(((uint8_t*)(arr))[3]) << 24) + ((uint64_t)(((uint8_t*)(arr))[4]) << 32) + ((uint64_t)(((uint8_t*)(arr))[5]) << 40) + ((uint64_t)(((uint8_t*)(arr))[6]) << 48) + ((uint64_t)(((uint8_t*)(arr))[7]) << 56))

#pragma optimize( "t", on )
void 
#ifdef _MSC_VER
__forceinline
#else
__attribute__((always_inline)) inline
#endif
bbs(uint8_t p1, uint8_t p2, uint64_t seed, uint8_t res[16]) {
    uint16_t M = p1 * p2;
    for (int i = 0; i < 16; i++) res[i] = (uint8_t)(((seed << 1) % M) % 0xff);
}

#pragma optimize( "", off )
void compress(struct sponge_state * state, uint8_t G[8], uint8_t H[8], uint8_t m[16]) {
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
    uint64_t splitmixState = state->squeezeIndex % (G[G[0]%8]+1) == 0 ? to64b(G) : to64l(G);
    splitmixState ^= primes[splitmixState % 16];
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

#pragma optimize( "", off )
void
#ifdef _MSC_VER
__forceinline
#else
__attribute__((always_inline)) inline
#endif
init_sponge(struct sponge_state* state, uint8_t key[16]) {
    state->squeezeIndex = 0;
    uint64_t splitmix_state = to64b(key) ^ to64l(&key[8]);
    for (int i = 0; i < 4; i++) state->keygen.s[i] = splitmix64(&splitmix_state);
    for (int i = 0; i < 672; i++) {
        state->state[0][i] = 0;
        state->state[1][i] = 0;
    }
}

#pragma optimize( "", off )
void
#ifdef _MSC_VER
__forceinline
#else
__attribute__((always_inline)) inline
#endif
transform(struct sponge_state* state) {
    state->squeezeIndex++;
    state->squeezeIndex %= 63;
    for (int i = 0; i < 672; i += 8) {
        uint8_t key[16];
        bbs(smallPrimes[state->state[0][i] % 54], smallPrimes[state->state[1][i] % 54], xoshiro256ss(&state->keygen), key);
        compress(state, &state->state[1][i], &state->state[0][i], key);
    }
}

#pragma optimize( "", off )
void ALMA_API absorb(struct sponge_state* state, uint8_t b[63]) {
    for (int i = 0; i < 63; i++) state->state[0][i] ^= b[i];
    transform(state);
}


uint8_t ALMA_API squeeze(struct sponge_state* state) {
    uint8_t b = ((state->state[0][state->squeezeIndex] ^ state->state[1][state->squeezeIndex]) * smallPrimes[((state->state[0][state->squeezeIndex] + state->squeezeIndex) ^ state->state[1][state->squeezeIndex])%54]) % 0xff;
    transform(state);
    return b;
}

#pragma optimize( "t", on )
const size_t
#ifdef _MSC_VER
__forceinline
#else
__attribute__((always_inline)) inline
#endif
inlen(size_t len) {
    return len + (63 - (len % 63));
}

#pragma optimize( "", off )
void ALMA_API hash(uint8_t *  src, size_t ss, uint8_t hsh[63]) {
    struct sponge_state state;
    uint8_t keygenInit[16];
    uint64_t sum = 0;
    for (size_t i = 0; i < ss; i++) sum += src[i];
    sum *= 12234324324251;
    sum = sum < 0 ? (-sum)^primes[(-sum)%16] : sum;
    bbs(smallPrimes[sum % 54], smallPrimes[(sum ^ 18446744073709551557) % 54], sum, keygenInit);
    init_sponge(&state, keygenInit);
    size_t actual = inlen(ss);
    uint8_t* target = (uint8_t*)calloc(actual, sizeof(uint8_t));
    if (target == NULL) { 
        perror("Nie udało się zaalokować pamięci"); 
        return;
    }
    memcpy(target, src, ss);
    for (size_t i = actual - 1; i > 0; i--) {
        target[i] ^= rijndael[xoshiro256ss(&state.keygen) % 0xff];
#ifdef _MSC_VER
        target[i] = splitmix64(&sum) % 2 ? _rotl8(target[i], splitmix64(&sum) % 7) : _rotr8(target[i], splitmix64(&sum) % 7);
#else
        if (splitmix64(&sum) % 2) rol(target[i], splitmix64(&sum) % 7);
        else asm volatile ("ror {%0,%1|%1,%0}" : : "r" (target[i]), "r" (splitmix64(&sum) % 7) : "cc")
#endif
    }
    for (int i = 0; i < actual; i += 63) absorb(&state, &target[i]);
    free(target);
    for (int i = 0; i < 63; i++) hsh[i] = squeeze(&state);
}