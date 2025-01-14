#ifndef ASSERT_H
#define ASSERT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>

void assert_print_equal_int_msg(const char *msg, int expected, int actual);
void assert_print_equal_size_t_msg(const char *msg, size_t expected, size_t actual);
void assert_print_equal_str_msg(const char *msg, const char *expected, const char *actual);


#define ASSERT_PRINT_EQUAL(MSG, expected, actual) \
    _Generic((expected) + 0,                      \
        int: assert_print_equal_int_msg,          \
        size_t: assert_print_equal_size_t_msg,    \
        default: assert_print_equal_str_msg)(MSG, expected, actual)

#define ASSERT_ERRNO(expected_errno, msg)                                                             \
    do                                                                                                \
    {                                                                                                 \
        if (errno != (expected_errno))                                                                \
        {                                                                                             \
            fprintf(stderr, "[FAIL] %s\n  expected errno: %d (%s)\n  got: %d (%s)\n",                 \
                    msg, (expected_errno), strerror(expected_errno),                                  \
                    errno, strerror(errno));                                                          \
            exit(EXIT_FAILURE);                                                                       \
        }                                                                                             \
        else                                                                                          \
        {                                                                                             \
            printf("[PASS] %s: errno is %d (%s)\n", msg, (expected_errno), strerror(expected_errno)); \
        }                                                                                             \
    } while (0)

#endif // ASSERT_H
