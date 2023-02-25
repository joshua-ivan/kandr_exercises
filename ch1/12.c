#include <stdio.h>

#define IN 1
#define OUT 0

void word_split(FILE *stream) {
    int c, state;

    state = OUT;
    while ((c = getc(stream)) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                putc('\n', stdout);
            }
            state = OUT;
        } else {
            if (state == OUT) {
                state = IN;
            }
            putc(c, stdout);
        }
    }
}

int main() {
    word_split(stdin);
}
