#ifndef __CIPHER_H_
#define __CIPHER_H_

#include <immintrin.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#pragma optimize( "", off )
#ifdef __cplusplus
extern "C" {
#endif // _cplusplus

#ifdef  CIPHER_EXPORTS 
#define CIPHER_API __declspec(dllexport)  
#else
#define CIPHER_API __declspec(dllimport)  
#endif

void CIPHER_API expand(uint8_t key[24], uint8_t result[24 * 13]);
void CIPHER_API cipher(uint8_t block[8], uint8_t key[24 * 13], uint8_t result[8]);

#ifdef __cplusplus
}
#endif // _cplusplus
#pragma optimize( "", on )
#endif