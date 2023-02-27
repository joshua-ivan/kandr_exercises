#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../minunit.h"
#include "kandr-01-16.h"

int tests_run = 0;

int assert_getline_params(int len, int exp_len, int buf_size, int exp_buf_size, char* str, char* exp_str) {
    return len == exp_len && buf_size == exp_buf_size && !strcmp(str, exp_str);
}

static const char* test_kandr_getline() {
    int buf_size = DEFAULT_BUFSIZE;
    FILE* fp = fopen("test-inputs/16/normal.txt", "r");
    char* str = malloc(sizeof(char) * buf_size);
    int len = kandr_getline(fp, &str, &buf_size);

    const char* fail_msg = "FAILURE: test_kandr_getline";
    char* expected_str = "The quick brown fox jumps over the lazy dog\n";
    mu_assert(fail_msg, assert_getline_params(len, 44, buf_size, DEFAULT_BUFSIZE, str, expected_str));

    free(str);
    fclose(fp);
    return 0;
}

static const char* test_kandr_getline__bounds() {
    int buf_size = 10;
    FILE* fp = fopen("test-inputs/16/bounds.txt", "r");
    char* str = malloc(sizeof(char) * buf_size);
    int len = kandr_getline(fp, &str, &buf_size);

    const char* fail_msg = "FAILURE: test_kandr_getline__bounds";
    char* expected_str = "abcdefgh\n";
    mu_assert(fail_msg, assert_getline_params(len, 9, buf_size, 10, str, expected_str));

    free(str);
    fclose(fp);
    return 0;
}

static const char* test_kandr_getline__empty() {
    int buf_size = 10;
    FILE* fp = fopen("test-inputs/16/empty.txt", "r");
    char* str = malloc(sizeof(char) * buf_size);
    int len = kandr_getline(fp, &str, &buf_size);

    const char* fail_msg = "FAILURE: test_kandr_getline__empty";
    char* expected_str = "";
    mu_assert(fail_msg, assert_getline_params(len, 0, buf_size, 10, str, expected_str));

    free(str);
    fclose(fp);
    return 0;
}

static const char* test_kandr_getline__null_buffer() {
    int buf_size = -1;
    FILE* fp = fopen("test-inputs/16/normal.txt", "r");
    char* str = NULL;
    int len = kandr_getline(fp, &str, &buf_size);

    const char* fail_msg = "FAILURE: test_kandr_getline__null_buffer";
    char* expected_str = "The quick brown fox jumps over the lazy dog\n";
    mu_assert(fail_msg, assert_getline_params(len, 44, buf_size, DEFAULT_BUFSIZE, str, expected_str));

    free(str);
    fclose(fp);
    return 0;
}

static const char* test_kandr_getline__large_line() {
    int buf_size = 10;
    FILE* fp = fopen("test-inputs/16/normal.txt", "r");
    char* str = malloc(sizeof(char) * buf_size);
    int len = kandr_getline(fp, &str, &buf_size);

    const char* fail_msg = "FAILURE: test_kandr_getline__large_line";
    char* expected_str = "The quick brown fox jumps over the lazy dog\n";
    mu_assert(fail_msg, assert_getline_params(len, 44, buf_size, 80, str, expected_str));

    free(str);
    fclose(fp);
    return 0;
}

static const char* test_longest_line() {
    FILE* fp = fopen("test-inputs/16/longest.txt", "r");
    char* longest = NULL;
    int length = longest_line(fp, &longest);

    const char* fail_msg = "FAILURE: test_longest_line";
    mu_assert(fail_msg, length == 7);
    mu_assert(fail_msg, !strcmp(longest, "filter\n"));

    free(longest);
    fclose(fp);
    return 0;
}

static const char* test_longest_line__empty() {
    FILE* fp = fopen("test-inputs/16/empty.txt", "r");
    char* longest = NULL;
    int length = longest_line(fp, &longest);

    const char* fail_msg = "FAILURE: test_longest_line__empty";
    mu_assert(fail_msg, length == 0);
    mu_assert(fail_msg, !strcmp(longest, ""));

    free(longest);
    fclose(fp);
    return 0;
}

static const char* test_longest_line__nonnull_input_line() {
    FILE* fp = fopen("test-inputs/16/longest.txt", "r");
    char* longest = malloc(sizeof(char) * 10);
    int length = longest_line(fp, &longest);

    const char* fail_msg = "FAILURE: test_longest_line__nonnull_input_line";
    mu_assert(fail_msg, length == 7);
    mu_assert(fail_msg, !strcmp(longest, "filter\n"));

    free(longest);
    fclose(fp);
    return 0;

}

static const char* all_tests() {
    mu_run_test(test_kandr_getline);
    mu_run_test(test_kandr_getline__bounds);
    mu_run_test(test_kandr_getline__empty);
    mu_run_test(test_kandr_getline__null_buffer);
    mu_run_test(test_kandr_getline__large_line);
    mu_run_test(test_longest_line);
    mu_run_test(test_longest_line__empty);
    mu_run_test(test_longest_line__nonnull_input_line);

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

