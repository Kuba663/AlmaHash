// HashFunc.h: plik dołączany dla standardowych systemowych plików dołączanych,
// lub pliki dołączane specyficzne dla projektu.

#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <immintrin.h>

#include "../CipherFunc/Cipher.h"

#ifdef  ALMA_EXPORTS 
#define ALMA_API __declspec(dllexport)  
#else
#define ALMA_API __declspec(dllimport)  
#endif

struct xoshiro256ss_state {
#ifdef _MSC_VER
	uint64_t __declspec(align(16)) s[4];
#else
	uint64_t s[4] __attribute__((aligned(16)));
#endif
};

struct sponge_state {
	uint8_t state[2][672];
	struct xoshiro256ss_state keygen;
	uint8_t squeezeIndex;
};

void ALMA_API init_sponge(struct sponge_state* state, uint8_t* key, size_t keySize);
void ALMA_API absorb(struct sponge_state* state, uint8_t b[63]);
uint8_t ALMA_API squeeze(struct sponge_state* state);

// TODO: W tym miejscu przywołaj dodatkowe nagłówki wymagane przez program.
