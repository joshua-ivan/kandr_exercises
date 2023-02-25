#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kandr-01-13.h"

#define IN 1
#define OUT 0

int* word_lengths(FILE* stream) {
    int c, state, current;
    int* lengths = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        lengths[i] = 0;
    }

    current = 0;
    state = OUT;
    while ((c = getc(stream)) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                int index = (current > 10) ? 9 : current - 1;
                ++lengths[index];
            }
            state = OUT;
        } else {
            if (state == OUT) {
                state = IN;
                current = 0;
            }
            ++current;
        }
    }

    return lengths;
}

char* build_histogram(int* counts, int counts_len) {
    int max = 0;
    for (int i = 0; i < counts_len; i++) {
        if (counts[i] > max) {
            max = counts[i];
        }
    }

    const int HISTO_LINE_LEN = 31;
    int histo_strlen = HISTO_LINE_LEN * (max + 1);
    char* histo = malloc(sizeof(char) * histo_strlen);
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < 10; j++) {
            int index = (HISTO_LINE_LEN * i) + (3 * j);
            histo[index] = ' ';
            histo[index + 1] = ((max - i) <= counts[j]) ? '*' : ' ';
            histo[index + 2] = ' ';
        }
        histo[(HISTO_LINE_LEN * i) + (HISTO_LINE_LEN - 1)] = '\n';
    }
    char* label = " 1  2  3  4  5  6  7  8  9 10+\0";
    strcpy((histo + (HISTO_LINE_LEN * max)), label);

    return histo;
}
