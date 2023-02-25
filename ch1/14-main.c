#include <stdio.h>
#include <stdlib.h>
#include "kandr-01-14.h"

int main() {
    int* lengths = char_frequency(stdin);
    char* histo = build_histogram(lengths, 4);
    printf("%s\n", histo);
    free(histo);
    free(lengths);
    return 0;
}
