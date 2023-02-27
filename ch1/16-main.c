#include <stdio.h>
#include <stdlib.h>
#include "kandr-01-16.h"

int main() {
    char* longest = NULL;
    int length = longest_line(stdin, &longest);
    printf("Longest line: %s\nLength: %d\n", longest, length);

    return 0;
}
