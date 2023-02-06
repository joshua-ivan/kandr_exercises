#include <stdio.h>
#include "kandr-01-11.h"

#define IN 1
#define OUT 0

void kandr_wc(FILE *stream, int* nl, int* nw, int *nc) {
    int c, state;

    state = OUT;
    *nl = *nw = *nc = 0;
    while ((c = getc(stream)) != EOF) {
        ++(*nc);
        if (c == '\n') {
            ++(*nl);
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++(*nw);
        }
    }
}

