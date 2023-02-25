#include <stdio.h>
#include <stdlib.h>
#include "kandr-01-13.h"

int main() {
    int* lengths = word_lengths(stdin);
    char* histo = build_histogram(lengths, 10);
    printf("%s\n", histo);
    free(histo);
    free(lengths);
    return 0;
}
