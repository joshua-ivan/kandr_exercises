#include <stdio.h>
#include <stdlib.h>
#include "../minunit.h"
#include "kandr-01-13.h"

int tests_run = 0;

int test_word_lengths(char* path, int expected[10]) {
    FILE *fp = fopen(path, "r");

    int* lengths = word_lengths(fp);
    for (int i = 0; i < 10; i++) {
        if (lengths[i] != expected[i]) {
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

static const char* test_kandr_word_lengths() {
    char* path = "13-test-inputs/normal.txt";
    const char* fail_msg = "FAILURE: test_kandr_word_lengths";
    int expected[10] = { 0, 0, 4, 2, 3, 0, 0, 0, 0, 0 };

    mu_assert(fail_msg, !test_word_lengths(path, expected));

    return 0;
}

static const char* test_kandr_word_lengths__extra_whitespace() {
    char* path = "13-test-inputs/whitespace.txt";
    const char* fail_msg = "FAILURE: test_kandr_word_lengths__extra_whitespace";
    int expected[10] = { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };

    mu_assert(fail_msg, !test_word_lengths(path, expected));

    return 0;
}

static const char* test_kandr_word_lengths__long_words() {
    char* path = "13-test-inputs/long.txt";
    const char* fail_msg = "FAILURE: test_kandr_word_lengths__long_words";
    int expected[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 };

    mu_assert(fail_msg, !test_word_lengths(path, expected));

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
    int counts_arr[10] = { 3, 3, 3, 2, 9, 6, 9, 5, 1, 1 };
    int* counts = build_counts(counts_arr);

    char* histo = build_histogram(counts, 10);
    FILE* expected = fopen("13-test-inputs/histo_normal.txt", "r");

    const char* fail_msg = "FAILURE: test_kandr_build_histogram";
    mu_assert(fail_msg, string_equals_file(histo, expected));

    fclose(expected);
    free(histo);
    free(counts);
    return 0;
}

static const char* all_tests() {
    mu_run_test(test_kandr_word_lengths);
    mu_run_test(test_kandr_word_lengths__extra_whitespace);
    mu_run_test(test_kandr_word_lengths__long_words);
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

