#include "Cipher.h"

#include "PermutationTable.h"

#ifdef _MSC_VER
#include <intrin.h>
#pragma intrinsic(_rotl8, _rotr8)
#else
#define _rotl8(n,d) (n << d)|(n >> (8 - d))
#define _rotr8(n,d) (n >> d)|(n << (INT_BITS - d))
#endif

const uint8_t volatile primes[54] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107,
109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179,
181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251 };

void volatile CIPHER_API expand(uint8_t key[24], uint8_t result[24 * 13]) {
	uint8_t tmp[24];
	memcpy(tmp, key, 24);
	for (int i = 0; i < 24 * 13; i += 24) {
		memcpy(&result[i], tmp, 24);
		for (int j = 0; j < 24; j++) {
			tmp[j] = j % 2 ? _rotl(tmp[j], 1) : _rotr(tmp[j], 1);
		}
	}
}

uint8_t volatile
#ifdef _MSC_VER
__forceinline
#else
__attribute__((always_inline)) inline
#endif
addMod(uint8_t a, uint8_t b, uint8_t m) {
	if (b != 0) {
		b = m - b;
		return a >= b ? a - b : m - b + a;
	}
	else return a;
}

uint8_t volatile
#ifdef _MSC_VER
__forceinline
#else
__attribute__((always_inline)) inline
#endif
arx(uint8_t a, uint8_t b) {
	return _rotl8(addMod(a, b, 63), 6) ^ b;
}

void volatile
#ifdef _MSC_VER
__forceinline
#else
__attribute__((always_inline)) inline
#endif
iteration(uint8_t R[4], uint8_t L[4], uint8_t key[4]) {
	for (int i = 0; i < 4; i++) {
		if (key[i] % 16 == 0) R[i] ^= pTable[arx(L[i], L[i]) % 16][L[i]];
		else if (key[i] % 6 == 0) R[i] ^= pTable[key[i] % 16][L[i]];
		else if (key[i] % 7 == 0) R[i] ^= pTable[key[i] % 16][arx(L[i], key[i])];
		else R[i] ^= arx(L[i], key[i]);
	}
}

void volatile CIPHER_API cipher(uint8_t block[8], uint8_t key[24 * 13], uint8_t result[8]) {
	uint8_t *R = block, *L = &block[4];
	for (int i = 0; i <= 78; i++) {
		const int index = 4 * i - 1;
		iteration(R, L, &key[index]);
#ifdef _MSC_VER
		uint8_t* tmp = L;
		L = R;
		R = tmp;
#else
		asm volatile ("xchg {%0,%1|%1,%0}" : : "r" (L), "r" (R) : "cc");
#endif
	}
}