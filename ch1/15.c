#include <stdio.h>

float fahr_to_celsius(float fahr) {
    return (5.0/9.0) * (fahr-32.0);
}

int main() {
    printf("  F      C\n");

    int lower, upper, step;
    lower = 0; upper = 300; step = 20;

    float fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, fahr_to_celsius(fahr));
        fahr += step;
    }
}
