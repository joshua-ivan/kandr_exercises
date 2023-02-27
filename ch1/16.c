#include <stdio.h>
#include <stdlib.h>
#include "kandr-01-16.h"

// print longest input line
/* int main() {
    int len; // current line length
    int max; // maximum length seen so far
    char line[MAXLINE]; // current input line
    char longest[MAXLINE]; // longest line saved here

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) { // there was a line
        printf("%s", longest);
    }

    return 0;
} */

void copy(char* to, char* from) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
    to[i] = '\0';
}

int longest_line(FILE* stream, char** longest) {
    int len = 0;
    int max = 0;
    int buf_size = DEFAULT_BUFSIZE;
    char* line = malloc(sizeof(char) * buf_size);
    if (*longest != NULL) {
        free(*longest);
    }
    *longest = malloc(sizeof(char));
    (*longest)[0] = '\0';

    while ((len = kandr_getline(stream, &line, &buf_size)) > 0) {
        if (len > max) {
            max = len;
            if ((*longest = realloc(*longest, sizeof(char) * max + 1)) == NULL) {
                *longest = malloc(sizeof(char));
                (*longest)[0] = '\0';
                return 0;
            }
            copy(*longest, line);
        }
    }

    free(line);
    return max;
}

int kandr_getline(FILE* stream, char** line, int* buf_size) {
    if (*line == NULL) {
        *buf_size = DEFAULT_BUFSIZE;
        *line = malloc(sizeof(char) * *buf_size);
    }

    int c = 0;
    int i = 0;
    while ((c = fgetc(stream)) != EOF && c != '\n') {
        if (i >= *buf_size - 1) {
            *buf_size *= 2;
            if ((*line = realloc(*line, sizeof(char) * *buf_size)) == NULL) {
                return -1;
            }
        }
        (*line)[i++] = c;
    }
    if (c == '\n') {
        (*line)[i++] = c;
    }
    (*line)[i] = '\0';

    return i;
}

