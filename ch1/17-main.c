#include <stdio.h>
#include <stdlib.h>
#include "kandr-01-17.h"

int main() {
    char* lines = long_lines(stdin);
    if (lines != NULL) {
        printf("%s\n", lines);
        free(lines);
    }

    return 0;
}
