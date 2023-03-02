#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kandr-01-19.h"

char* reverse(char* str) {
    int len = strlen(str);
    char* rev = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0';

    return rev;
}

char* multiline_reverse(FILE* stream) {
    char* output = NULL;
    char* current = NULL;
    size_t length = 0;
    ssize_t read;

    int output_length = 0;
    while ((read = getline(&current, &length, stream)) != -1) {
        output_length += read;
        output = realloc(output, sizeof(char) * (output_length + 1));
        strcat(output, current);
    }
    free(current);

    char* rev = reverse(output);
    free(output);
    return rev;
}
