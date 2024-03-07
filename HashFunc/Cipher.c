#include "Cipher.h"

void expand(uint8_t key[24], uint8_t result[24 * 13]) {
	for (int i = 0; i < 13; i++) {
		memcpy(&result[24*i], key, 24);
	}

}

void cipher(uint8_t block[8], uint8_t key[24 * 13], uint8_t result[8]) {

}