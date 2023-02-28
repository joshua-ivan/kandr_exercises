#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kandr-01-17.h"

char* long_lines(FILE* stream) {
    char* output = NULL;
    char* current = NULL;
    size_t length = 0;
    ssize_t read;

    int output_length = 0;
    while ((read = getline(&current, &length, stream)) != -1) {
        if (read > 80) {
            output_length += read;
            output = realloc(output, sizeof(char) * (output_length + 1));
            strcat(output, current);
        }
    }

    free(current);
    return output;
}
