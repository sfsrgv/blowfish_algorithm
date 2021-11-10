#include <time.h>
#include "string_and_uin64_functions.h"

char *make_array_of_chars_from_bytes(const uint64_t *buffer) {
    char *text = "";
    asprintf(&text, "%c%c%c%c%c%c%c%c",
             (char) ((*buffer >> 56) & 0xFF),
             (char) ((*buffer >> 48) & 0xFF),
             (char) ((*buffer >> 40) & 0xFF),
             (char) ((*buffer >> 32) & 0xFF),
             (char) ((*buffer >> 24) & 0xFF),
             (char) ((*buffer >> 16) & 0xFF),
             (char) ((*buffer >> 8) & 0xFF),
             (char) ((*buffer) & 0xFF));
    return text;
}

uint64_t make_uint64_from_array_of_chars(const char *array) {
    return (uint64_t) array[0] << 56 | (uint64_t) array[1] << 48 |
           (uint64_t) array[2] << 40 | (uint64_t) array[3] << 32 |
           (uint64_t) array[4] << 24 | (uint64_t) array[5] << 16 |
           (uint64_t) array[6] << 8 | (uint64_t) array[7];
}

void split_uint64(const uint64_t *number, uint32_t *left, uint32_t *right) {
    *left = ((*number >> 56) & 0xFF) << 24 |
            ((*number >> 48) & 0xFF) << 16 |
            ((*number >> 40) & 0xFF) << 8 |
            (*number >> 32 & 0xFF);
    *right = ((*number >> 24) & 0xFF) << 24 |
             ((*number >> 16) & 0xFF) << 16 |
             ((*number >> 8) & 0xFF) << 8 |
             (*number & 0xFF);
}

time_t global_time = 0;

int64_t degree_of_ten[10] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};

uint64_t convert_string_to_uint64(const char *line){
    uint64_t number = 0;
    for (size_t i = 0; i <= strlen(line) - 2; ++i) {
        number *= 10;
        number += (uint64_t)(line[i] - '0');
    }
    return number;
}
