#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../minunit.h"
#include "kandr-01-20.h"

int tests_run = 0;

int assert_expand(char* s, char* exp_str, int exp_res) {
    int buf_size = 8;
    char* str = malloc(sizeof(char) * buf_size);
    strcpy(str, s);

    int result = expand_tab(&str, &buf_size) == exp_res && !strcmp(exp_str, str);
    free(str);
    return result;
}

static const char* test_expand_tab() {
    const char* fail_msg = "FAILURE: test_expand_tab";
    mu_assert(fail_msg, assert_expand("\ttest", "    test", 1));
    mu_assert(fail_msg, assert_expand(" \ttest", "    test", 1));
    mu_assert(fail_msg, assert_expand("\t\ttest", "    \ttest", 1));
    mu_assert(fail_msg, assert_expand("test", "test", 0));

    return 0;
}

static const char* test_detab() {
    FILE* fp = fopen("test-inputs/20/input.txt", "r");
    char* output = detab(fp);

    char* expected = "    test\n    test\n        test\n        test\n            test\n            test\n\n";
    const char* fail_msg = "FAILURE: test_detab";
    mu_assert(fail_msg, !strcmp(expected, output));

    free(output);
    fclose(fp);
    return 0;
}

static const char* all_tests() {
    mu_run_test(test_expand_tab);
    mu_run_test(test_detab);

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

