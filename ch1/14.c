#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kandr-01-14.h"
#define IN 1
#define OUT 0

int* char_frequency(FILE* stream) {
    int* freq = malloc(sizeof(int) * 4);
    for (int i = 0; i < 4; i++) {
        freq[i] = 0;
    }

    char c;
    while ((c = getc(stream)) != EOF) {
        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
            freq[0]++;
        } else if ('0' <= c && c <= '9') {
            freq[1]++;
        } else if (c == ' ' || c == '\n' || c == '\t') {
            freq[2]++;
        } else {
            freq[3]++;
        }
    }

    return freq;
}

char* build_histogram(int* counts, int counts_len) {
    int max = 0;
    for (int i = 0; i < counts_len; i++) {
        if (counts[i] > max) {
            max = counts[i];
        }
    }

    const int HISTO_LINE_LEN = 21;
    int histo_strlen = HISTO_LINE_LEN * (max + 1);
    char* histo = malloc(sizeof(char) * histo_strlen);
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < 4; j++) {
            int index = (HISTO_LINE_LEN * i) + (5 * j);
            histo[index] = ' ';
            histo[index + 1] = ' ';
            histo[index + 2] = ((max - i) <= counts[j]) ? '*' : ' ';
            histo[index + 3] = ' ';
            histo[index + 4] = ' ';
        }
        histo[(HISTO_LINE_LEN * i) + (HISTO_LINE_LEN - 1)] = '\n';
    }
    char* label = " a-z  0-9  wts  etc \0";
    strcpy((histo + (HISTO_LINE_LEN * max)), label);

    return histo;
}
