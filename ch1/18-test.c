#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../minunit.h"
#include "kandr-01-18.h"

int tests_run = 0;

static const char* test_clean_trailing_whitespace() {
    FILE* fp = fopen("test-inputs/18/normal.txt", "r");
    char* output = clean_trailing_whitespace(fp);

    char* expected = "lorem\nipsum\ntest\n";
    const char* fail_msg = "FAILURE: test_clean_trailing_whitespace";
    mu_assert(fail_msg, !strcmp(output, expected));

    free(output);
    return 0;
}

static const char* all_tests() {
    mu_run_test(test_clean_trailing_whitespace);

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

