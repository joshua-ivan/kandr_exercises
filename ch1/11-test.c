#include <stdio.h>
#include "../minunit.h"
#include "kandr-01-11.h"

int tests_run = 0;

static const char* test_kandr_wc() {
    FILE *fp = fopen("test-inputs/11/normal.txt", "r");

    int nl, nw, nc;
    kandr_wc(fp, &nl, &nw, &nc);
    const char* fail_msg = "FAILURE: test_kandr_wc";
    printf("test_kandr_wc: %d %d %d\n", nl, nw, nc);
    mu_assert(fail_msg, nl == 2 && nw == 4 && nc == 20);

    fclose(fp);

    return 0;
}

static const char* test_kandr_wc_newlines() {
    FILE *fp = fopen("test-inputs/11/newlines.txt", "r");

    int nl, nw, nc;
    kandr_wc(fp, &nl, &nw, &nc);
    const char* fail_msg = "FAILURE: test_kandr_wc_newlines";
    printf("test_kandr_wc_newlines: %d %d %d\n", nl, nw, nc);
    mu_assert(fail_msg, nl == 4 && nw == 0 && nc == 4);

    fclose(fp);

    return 0;
}

static const char* test_kandr_wc_whitespace() {
    FILE *fp = fopen("test-inputs/11/whitespace.txt", "r");

    int nl, nw, nc;
    kandr_wc(fp, &nl, &nw, &nc);
    const char* fail_msg = "FAILURE: test_kandr_wc_whitespace";
    printf("test_kandr_wc_whitespace: %d %d %d\n", nl, nw, nc);
    mu_assert(fail_msg, nl == 2 && nw == 0 && nc == 8);

    fclose(fp);

    return 0;
}

static const char* all_tests() {
    mu_run_test(test_kandr_wc);
    mu_run_test(test_kandr_wc_newlines);
    mu_run_test(test_kandr_wc_whitespace);

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

