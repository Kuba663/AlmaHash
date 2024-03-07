#ifndef __CIPHER_H_
#define __CIPHER_H_

#include <immintrin.h>
#include <stdint.h>
#include <stdlib.h>

void cipher(uint8_t block[8], uint8_t key[24 * 13], uint8_t result[8]);

#endif