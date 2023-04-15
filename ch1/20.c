#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kandr-01-20.h"

int expand_tab(char** str, int* buf_size) {
    int i = 0;
    while (i < *buf_size && (*str)[i] != '\0') {
        if ((*str)[i] == '\t') {
            *buf_size += TABSIZE;
            *str = realloc(*str, sizeof(char) * *buf_size);

            int num_spaces = TABSIZE - (i % TABSIZE) - 1;
            for (int j = *buf_size - TABSIZE - 1; j > i; j--) {
                (*str)[j + num_spaces] = (*str)[j];
            }

            do {
                (*str)[i++] = ' ';
            } while (i % TABSIZE != 0);

            return 1;
        } else {
            i++;
        }
    }
    return 0;
}

char* detab(FILE* stream) {
    char* output = NULL;
    char* current = NULL;
    size_t length = 0;
    ssize_t read;

    int output_length = 0;
    while ((read = getline(&current, &length, stream)) != -1) {
        while (expand_tab(&current, (int *)&length)) ;

        output_length += length;
        output = realloc(output, sizeof(char) * (output_length + 1));
        strcat(output, current);
    }

    free(current);
    return output;
}
