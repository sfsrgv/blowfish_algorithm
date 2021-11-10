#include "string_functions.h"

char *print_as_bytes(uint64_t buffer) {
    char *text = "";
    asprintf(&text, "%c%c%c%c%c%c%c%c",
             (char) ((buffer >> 56) & 0xFF),
             (char) ((buffer >> 48) & 0xFF),
             (char) ((buffer >> 40) & 0xFF),
             (char) ((buffer >> 32) & 0xFF),
             (char) ((buffer >> 24) & 0xFF),
             (char) ((buffer >> 16) & 0xFF),
             (char) ((buffer >> 8) & 0xFF),
             (char) ((buffer) & 0xFF));
    return text;
}

uint64_t string_to_uint64(char *line) {
    size_t left_size = strlen(line) / 2;
    char *left = (char *) malloc(left_size * sizeof(char));
    strncpy(left, line, left_size);
    uint64_t deg = 1;
    for (int i = 1; i < strlen(line) - left_size; ++i) {
        deg *= 10;
    }
    uint64_t number = atoll(left) * deg;
    uint64_t right = atoll(line + left_size);
    free(left);
    return number + right;
}