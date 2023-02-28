#include <stdio.h>
#include <stdlib.h>
#include "kandr-01-18.h"

int main() {
    char* lines = clean_trailing_whitespace(stdin);
    if (lines != NULL) {
        printf("%s\n", lines);
        free(lines);
    }

    return 0;
}
