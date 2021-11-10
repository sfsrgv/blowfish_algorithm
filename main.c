#include <stdio.h>
#include <string.h>
#include <bits/types/time_t.h>
#include <time.h>

#include "blowfish_algorithm.h"
#include "string_functions.h"

int main() {
    FILE *text_file = fopen("big_text.txt", "r");
    if (text_file == NULL) {
        printf("Error while opening file");
        return 1;
    }
    char *buffer = (char *) malloc(sizeof(char) * 8);
    if (buffer == NULL) {
        printf("Error while allocating memory");
        return 1;
    }
    time_t start_time = time(NULL);
    size_t number_of_read_bytes = fread(buffer, 1, 8, text_file);
    FILE *code_file = fopen("coded.txt", "w");
    while (number_of_read_bytes != 0) {
        uint64_t coded_line = code(buffer);
        fprintf(code_file, "%022lu\n", coded_line);
        number_of_read_bytes = fread(buffer, 1, 8, text_file);
    }
    time_t finish_time = time(NULL);
    printf("Process of coding finished after %ld sec\n", finish_time - start_time);
    free(buffer);
    fclose(code_file);

    code_file = fopen("coded.txt", "r");
    start_time = time(NULL);
    buffer = (char *) malloc(sizeof(char) * 23);
    number_of_read_bytes = fread(buffer, 1, 23, code_file);
    FILE *decode_file = fopen("decoded.txt", "w");
    while (number_of_read_bytes != 0) {
        uint64_t decoded_line = decode(string_to_uint64(buffer));
        fprintf(decode_file, "%s", print_as_bytes(decoded_line));
        number_of_read_bytes = fread(buffer, 1, 23, code_file);
    }
    finish_time = time(NULL);
    printf("Process of decoding finished after %ld sec\n", finish_time - start_time);
    free(buffer);

    return 0;
}


