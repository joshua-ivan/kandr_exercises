#include <stdio.h>

int main() {
    /* error: expected expression before ‘;’ token
    printf(;"hello, world\n"); */

    /* error: missing terminating ' character
    printf("hello, world\n"'); */

    /* error: expected expression before ‘)’ token
    printf("hello, world\n"?); */
    
    /* compiles; prints extra character */
    printf("hellof, world\n");
}
