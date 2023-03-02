#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../minunit.h"
#include "kandr-01-19.h"

int tests_run = 0;

static const char* test_reverse() {
    char* reversed = reverse("PREPARE FOR DEALLOCATION");
    char* expected = "NOITACOLLAED ROF ERAPERP";

    const char* fail_msg = "FAILURE: test_reverse";
    mu_assert(fail_msg, !strcmp(expected, reversed));

    free(reversed);
    return 0;
}

static const char* test_multiline_reverse() {
    FILE* fp = fopen("test-inputs/19/normal.txt", "r");
    char* output = multiline_reverse(fp);
    char* expected = "\n\nNOITACOLLAED\nROF\nERAPERP";

    const char* fail_msg = "FAILURE: test_multiline_reverse";
    mu_assert(fail_msg, !strcmp(expected, output));

    free(output);
    fclose(fp);
    return 0;
}

static const char* all_tests() {
    mu_run_test(test_reverse);
    mu_run_test(test_multiline_reverse);

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

