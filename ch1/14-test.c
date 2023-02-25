#include <stdio.h>
#include <stdlib.h>
#include "../minunit.h"
#include "kandr-01-14.h"

int tests_run = 0;

static const char* test_kandr_char_frequency() {
    FILE *fp = fopen("test-inputs/14/hi.c", "r");

    int* freq = char_frequency(fp);
    int expected[4] = { 13, 4, 7, 5 };

    const char* fail_msg = "FAILURE: test_kandr_char_frequency";
    for (int i = 0; i < 4; i++) {
        mu_assert(fail_msg, freq[i] == expected[i]);
    }

    free(freq);
    fclose(fp);
    return 0;
}

int* build_counts(int counts_arr[10]) {
    int* counts = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        counts[i] = counts_arr[i];
    }
    return counts;
}

int string_equals_file(char* str, FILE* f) {
    char c = '\0';
    int i = 0;

    while ((c = getc(f)) != EOF && str[i] != '\0') {
        if (c != str[i++]) {
            return 0;
        }
    }

    return 1;
}

static const char* test_kandr_build_histogram() {
    int counts_arr[10] = { 13, 4, 7, 5 };
    int* counts = build_counts(counts_arr);

    char* histo = build_histogram(counts, 4);
    FILE* expected = fopen("test-inputs/14/histo.txt", "r");

    const char* fail_msg = "FAILURE: test_kandr_build_histogram";
    mu_assert(fail_msg, string_equals_file(histo, expected));

    fclose(expected);
    free(histo);
    free(counts);
    return 0;
}

static const char* all_tests() {
    mu_run_test(test_kandr_char_frequency);
    mu_run_test(test_kandr_build_histogram);

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

