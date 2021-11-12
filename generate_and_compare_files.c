#include "generate_and_compare_files.h"

void compare_files(char *lhs_file_name, char *rhs_file_name) {
    FILE *rhs_file = fopen(rhs_file_name, "r");
    FILE *lhs_file = fopen(lhs_file_name, "r");
    if (!rhs_file || !lhs_file)
        return;
    char lhs_symbol = 0;
    char rhs_symbol = 0;
    int i = 1;
    rhs_symbol = (char) getc(rhs_file);
    lhs_symbol = (char) getc(lhs_file);
    while (rhs_symbol != EOF) {
        if (lhs_symbol != rhs_symbol || lhs_symbol == EOF) {
            printf("Files are not the same on symbol %d: %c != %c\n", i, lhs_symbol, rhs_symbol);
            fclose(lhs_file);
            fclose(rhs_file);
            return;
        }
        rhs_symbol = (char) getc(rhs_file);
        lhs_symbol = (char) getc(lhs_file);
        ++i;
    }

    printf("Files are the same\n");
    fclose(lhs_file);
    fclose(rhs_file);
}

void generate_text(uint64_t size) {
    FILE* file = fopen("text.txt", "w");
    int line = 0;
    for (uint64_t i = 0; i < size; ++i) {
        ++line;
        int symbol = rand() % 82 + 32;
        fprintf(file, "%c", (char)symbol);
    }
    fclose(file);
}
