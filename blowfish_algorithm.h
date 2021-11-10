#ifndef BLOWFISH_ALGORITHM_BLOWFISH_ALGORITHM_H
#define BLOWFISH_ALGORITHM_BLOWFISH_ALGORITHM_H

#include <stdint-gcc.h>

#include "string_and_uin64_functions.h"

#define CODE 0
#define DECODE 1

void swap(uint32_t *left, uint32_t *right);

uint32_t blowfish_function(const uint32_t* number);

void round_function(uint32_t *left, uint32_t *right, const uint32_t* key);

uint64_t blowfish(uint64_t *number, int operation);


#endif //BLOWFISH_ALGORITHM_BLOWFISH_ALGORITHM_H
