#ifndef CHAR_READING_H
#define CHAR_READING_H

#include <malloc.h>

void free_char_auto_ptr(char **ptr);

#define char_auto_ptr char* __attribute__((cleanup(free_char_auto_ptr)))

#endif //CHAR_READING_H
