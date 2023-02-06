#include <stdio.h>
#include "kandr-01-11.h"

int main() {
    int nl, nw, nc;
    kandr_wc(stdin, &nl, &nw, &nc);
    printf("%d %d %d\n", nl, nw, nc);
}
