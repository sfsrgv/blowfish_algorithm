#include <stdio.h>
#include <string.h>
#include <bits/types/time_t.h>
#include <time.h>

#include "blowfish_algorithm.h"
#include "string_and_uin64_functions.h"

extern time_t global_time;

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
        uint64_t number = make_uint64_from_array_of_chars(buffer);
        uint64_t coded_line = blowfish(&number, CODE);
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
    time_t time_for_decoding = 0;
    time_t time_for_printing = 0;
    time_t time_for_converting = 0;
    time_t time_for_reading = 0;
    time_t timers[10];
    while (number_of_read_bytes != 0) {
        timers[0] = time(NULL);
        uint64_t number = convert_string_to_uint64(buffer);
        timers[1] = time(NULL);

        timers[2] = time(NULL);
        uint64_t decoded_line = blowfish(&number, DECODE);
        timers[3] = time(NULL);

        timers[4] = time(NULL);
        fprintf(decode_file, "%s", make_array_of_chars_from_bytes(&decoded_line));
        timers[5] = time(NULL);

        timers[6] = time(NULL);
        number_of_read_bytes = fread(buffer, 1, 23, code_file);
        timers[7] = time(NULL);

        time_for_printing += timers[5] - timers[4];
        time_for_reading += timers[7] - timers[6];
        time_for_decoding += timers[3] - timers[2];
        time_for_converting += timers[1] - timers[0];
    }
    finish_time = time(NULL);
    printf("Process of decoding finished after %ld sec\nTime for decoding: %ld\nTime for printing: %ld\nTime for reading: %ld\nTime for converting: %ld\n",
           finish_time - start_time, time_for_decoding, time_for_printing, time_for_reading, time_for_converting);
    printf("Time for counting 10 degree: %ld", global_time);
    free(buffer);
    return 0;
}


