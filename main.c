#include <stdio.h>
#include <string.h>
#include <bits/types/time_t.h>
#include <time.h>

#include "blowfish_algorithm.h"
#include "string_and_uin64_functions.h"
#include "generate_and_compare_files.h"
#include "char_reading.h"

int main() {
    time(NULL);
    printf("Enter size of text to code and decode it in bytes: ");
    uint64_t size;
    scanf("%lu", &size);
    generate_text(size);

    FILE *text_file = fopen("text.txt", "r");
    if (text_file == NULL) {
        printf("Error while opening file");
        return 1;
    }
    char* buffer = (char *) malloc(sizeof(char) * 8);
    if (buffer == NULL) {
        printf("Error while allocating memory");
        return 1;
    }
    time_t start_time = time(NULL);
    size_t number_of_read_bytes = fread(buffer, 1, 8, text_file);
    FILE *code_file = fopen("coded.txt", "w");
    while (number_of_read_bytes != 0) {
        uint64_t number = make_uint64_from_array_of_chars(buffer);
        uint64_t coded_line = blowfish(&number, CODE);
        fprintf(code_file, "%022lu", coded_line);
        free(buffer);
        buffer = (char *) malloc(sizeof(char) * 22);
        number_of_read_bytes = fread(buffer, 1, 8, text_file);
    }
    time_t finish_time = time(NULL);
    printf("Process of coding finished after %ld sec\n", finish_time - start_time);
    free(buffer);
    fclose(code_file);
    code_file = fopen("coded.txt", "r");
    start_time = time(NULL);
    buffer = (char *) malloc(sizeof(char) * 22);
    number_of_read_bytes = fread(buffer, 1, 22, code_file);
    buffer[22] = '\0';
    FILE *decode_file = fopen("decoded.txt", "w");
    while (number_of_read_bytes != 0) {
        uint64_t number = convert_string_to_uint64(buffer);
        uint64_t decoded_line = blowfish(&number, DECODE);
        char_auto_ptr line = make_array_of_chars_from_bytes(&decoded_line);
        fprintf(decode_file, "%s", line);
        free(buffer);
        buffer = (char *) malloc(sizeof(char) * 22);
        number_of_read_bytes = fread(buffer, 1, 22, code_file);
        buffer[22] = '\0';
    }
    finish_time = time(NULL);
    printf("Process of decoding finished after %ld\n",finish_time - start_time);
    fclose(decode_file);
    compare_files("text.txt", "decoded.txt");
    return 0;
}


