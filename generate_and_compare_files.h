#ifndef BLOWFISH_ALGORITHM_GENERATE_AND_COMPARE_FILES_H
#define BLOWFISH_ALGORITHM_GENERATE_AND_COMPARE_FILES_H
#include <stdio.h>
#include <bits/types/FILE.h>
#include <stdlib.h>
#include <stdint-gcc.h>

// Prints if given files have equal texts
void compare_files(char* lhs_file, char* rhs_file);

// Generates random text with 'size' symbols
void generate_text(uint64_t size);

#endif //BLOWFISH_ALGORITHM_GENERATE_AND_COMPARE_FILES_H
