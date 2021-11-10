#ifndef BLOWFISH_ALGORITHM_BLOWFISH_ALGORITHM_H
#define BLOWFISH_ALGORITHM_BLOWFISH_ALGORITHM_H

#include <stdint-gcc.h>

void swap(uint32_t *left, uint32_t *right);

uint32_t blowfish_function(uint32_t number);

void round_function(uint32_t *left, uint32_t *right, uint32_t key);

uint64_t code(const char *buffer);

uint64_t decode(uint64_t buffer);

#endif //BLOWFISH_ALGORITHM_BLOWFISH_ALGORITHM_H
