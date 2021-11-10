#ifndef BLOWFISH_ALGORITHM_STRING_AND_UIN64_FUNCTIONS_H
#define BLOWFISH_ALGORITHM_STRING_AND_UIN64_FUNCTIONS_H

#include <stdint-gcc.h>
#include <stddef.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#include "asprintf.h"

char *make_array_of_chars_from_bytes(const uint64_t* buffer);

uint64_t convert_string_to_uint64(const char *line);

void split_uint64(const uint64_t* number, uint32_t *left, uint32_t *right);

uint64_t make_uint64_from_array_of_chars(const char *array);

#endif //BLOWFISH_ALGORITHM_STRING_AND_UIN64_FUNCTIONS_H
