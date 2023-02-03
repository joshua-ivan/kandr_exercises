#include <stdio.h>

int main() {
    int c, white;

    white = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            white++;
        }
        if (c == '\t') {
            white++;
        }
        if (c == ' ') {
            white++;
        }
    }

    printf("%d\n", white);
}
