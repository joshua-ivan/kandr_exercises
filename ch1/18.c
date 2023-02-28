#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kandr-01-18.h"

char* clean_trailing_whitespace(FILE* stream) {
    char* output = NULL;
    char* current = NULL;
    size_t length = 0;
    ssize_t read;

    int output_length = 0;
    while ((read = getline(&current, &length, stream)) != -1) {
        if (read == 1 && (current[0] == '\n' || current[0] == '\0')) {
            continue;
        }

        int index = 0;
        while (current[index] == ' ' || current[index] == '\t') {
            index++;
        }

        output_length += (read - index);
        output = realloc(output, sizeof(char) * (output_length + 1));
        strcat(output, (current + index));
    }

    free(current);
    return output;
}

