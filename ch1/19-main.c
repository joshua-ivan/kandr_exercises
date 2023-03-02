#include <stdio.h>
#include <stdlib.h>
#include "kandr-01-19.h"

int main() {
    char* rev = multiline_reverse(stdin);
    if (rev != NULL) {
        printf("%s\n", rev);
        free(rev);
    }

    return 0;
}

