// HashFunc.h: plik dołączany dla standardowych systemowych plików dołączanych,
// lub pliki dołączane specyficzne dla projektu.

#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <immintrin.h>

struct xoshiro256ss_state {
#ifdef _MSC_VER
	uint64_t __declspec(align(16)) s[4];
#else
	uint64_t s[4] __attribute__((aligned(16)));
#endif
};
// TODO: W tym miejscu przywołaj dodatkowe nagłówki wymagane przez program.
