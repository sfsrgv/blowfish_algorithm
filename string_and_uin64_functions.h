#ifndef BLOWFISH_ALGORITHM_STRING_FUNCTIONS_H
#define BLOWFISH_ALGORITHM_STRING_FUNCTIONS_H

#include <stdint-gcc.h>
#include <stddef.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "asprintf.h"

char *print_as_bytes(uint64_t buffer);

uint64_t string_to_uint64(char *line);

#endif //BLOWFISH_ALGORITHM_STRING_FUNCTIONS_H
