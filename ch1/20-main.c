#include <stdio.h>
#include <stdlib.h>
#include "kandr-01-20.h"

int main() {
    char* s = detab(stdin);
    if (s != NULL) {
        printf("%s\n", s);
        free(s);
    }

    return 0;
}

