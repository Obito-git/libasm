#include "assert.h"

void assert_print_equal_int_msg(const char *msg, int expected, int actual)
{
    if (expected != actual)
    {
        fprintf(stderr, "[FAIL] %s\n  expected: %d\n  got: %d\n",
                msg, expected, actual);
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("[PASS] %s: expected %d, got %d\n", msg, expected, actual);
    }
}

void assert_print_equal_size_t_msg(const char *msg, size_t expected, size_t actual)
{
    if (expected != actual)
    {
        fprintf(stderr, "[FAIL] %s\n  expected: %zu\n  got: %zu\n",
                msg, expected, actual);
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("[PASS] %s: expected %zu, got %zu\n", msg, expected, actual);
    }
}

void assert_print_equal_str_msg(const char *msg, const char *expected, const char *actual)
{
    if (strcmp(expected, actual) != 0)
    {
        fprintf(stderr, "[FAIL] %s\n  expected: \"%s\"\n  got: \"%s\"\n",
                msg, expected, actual);
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("[PASS] %s: expected \"%s\", got \"%s\"\n", msg, expected, actual);
    }
}