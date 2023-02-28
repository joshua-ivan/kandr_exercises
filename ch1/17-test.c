#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../minunit.h"
#include "kandr-01-17.h"

int tests_run = 0;

static const char* test_long_lines() {
    FILE* fp = fopen("test-inputs/17/normal.txt", "r");
    char* lines = long_lines(fp);

    char* expected = "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\neeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n";
    const char* fail_msg = "FAILURE: test_long_lines";
    printf("%s\n", lines);
    mu_assert(fail_msg, !strcmp(lines, expected));

    free(lines);
    return 0;
}

static const char* all_tests() {
    mu_run_test(test_long_lines);

    return 0;
}

int main(int argc, char **argv) {
    const char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}

