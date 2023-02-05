#include <stdio.h>

int main() {
    int c, extra_white;

    extra_white = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            if (!extra_white) {
                putchar(c);
            }
            extra_white = 1;
        } else {
            putchar(c);
            extra_white = 0;
        }
    }
}
