// Sofa Sergeeva
//
// Code and decode text whit blowfish algorithm
//
// To compile program use command:
// gcc main.c blowfish_algorithm.c string_and_uin64_functions.c char_reading.c generate_and_compare_files.c

#include <stdio.h>
#include <string.h>
#include <bits/types/time_t.h>
#include <time.h>

#include "blowfish_algorithm.h"
#include "string_and_uin64_functions.h"
#include "generate_and_compare_files.h"
#include "char_reading.h"
#include "safe_macroses.h"

int main() {
    // Generating random text
    printf("Enter size of text to code and decode it in bytes: ");
    uint64_t size;
    scanf("%lu", &size);
    generate_text(size);

    // Coding
    FILE *text_file;
    SAFE_OPENING_FILE(text_file, "text.txt", "r");

    char_auto_ptr buffer;
    SAFE_MALLOC(buffer, char, sizeof(char) * 8);
    size_t number_of_read_bytes = fread(buffer, 1, 8, text_file);

    time_t start_time;
    SAFE_GETTING_TIME(start_time);

    FILE *code_file;
    SAFE_OPENING_FILE(code_file, "coded.txt", "w");
    while (number_of_read_bytes != 0) {
        uint64_t number = make_uint64_from_array_of_chars(buffer);
        uint64_t coded_line = blowfish(&number, CODE);
        fprintf(code_file, "%022lu", coded_line);
        free(buffer);
        SAFE_MALLOC(buffer, char, sizeof(char) * 22);
        number_of_read_bytes = fread(buffer, 1, 8, text_file);
    }
    time_t finish_time;
    SAFE_GETTING_TIME(finish_time);
    printf("Process of coding finished after %ld sec\n", finish_time - start_time);

    free(buffer);
    fclose(code_file);
    fclose(text_file);

    // Decoding
    SAFE_GETTING_TIME(start_time);

    SAFE_OPENING_FILE(code_file,"coded.txt", "r");
    SAFE_MALLOC(buffer, char, sizeof(char) * 22);
    number_of_read_bytes = fread(buffer, 1, 22, code_file);
    buffer[22] = '\0';

    FILE *decode_file;
    SAFE_OPENING_FILE(decode_file,"decoded.txt", "w");
    while (number_of_read_bytes != 0) {
        uint64_t number = convert_string_to_uint64(buffer);
        uint64_t decoded_line = blowfish(&number, DECODE);

        char_auto_ptr line = make_array_of_chars_from_bytes(&decoded_line);
        fprintf(decode_file, "%s", line);

        free(buffer);
        SAFE_MALLOC(buffer, char, sizeof(char) * 22);
        number_of_read_bytes = fread(buffer, 1, 22, code_file);
        buffer[22] = '\0';
    }
    SAFE_GETTING_TIME(finish_time);
    printf("Process of decoding finished after %ld\n",finish_time - start_time);

    fclose(decode_file);
    fclose(code_file);

    // Testing coding and decoding
    compare_files("text.txt", "decoded.txt");
    return 0;
}


