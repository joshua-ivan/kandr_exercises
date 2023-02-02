#include <stdio.h>

int main() {
    printf("  C      F\n");
    for (int celsius = 300; celsius >= 0; celsius = celsius - 20) {
        printf("%3.0f %6.1f\n", (float)celsius, (celsius*1.8) + 32.0);
    }
}
