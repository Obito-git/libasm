#include "test.h"

void ft_bzero_test()
{
    printf("ft_bzero started:\n");

    {
        char buffer[10] = "123456789";
        char expected[10] = "123456789";

        ft_bzero(buffer, 5);
        memset(expected, 0, 5);
        ASSERT_PRINT_EQUAL("Test 1: ft_bzero(buffer, 5)", memcmp(buffer, expected, 10), 0);
    }

    {
        char buffer[5] = "abcde";
        char expected[5] = "abcde";

        ft_bzero(buffer, 0);
        ASSERT_PRINT_EQUAL("Test 2: ft_bzero(buffer, 0)", memcmp(buffer, expected, 5), 0);
    }

    {
        char buffer[8] = "ABCDEFG";
        char expected[8] = "ABCDEFG";

        ft_bzero(buffer, 8);
        memset(expected, 0, 8);
        ASSERT_PRINT_EQUAL("Test 3: ft_bzero(buffer, 8)", memcmp(buffer, expected, 8), 0);
    }

    {
        char buffer[1] = "X";
        char expected[1] = "X";

        ft_bzero(buffer, 1);
        memset(expected, 0, 1);
        ASSERT_PRINT_EQUAL("Test 4: ft_bzero(buffer, 1)", memcmp(buffer, expected, 1), 0);
    }

    {
        char buffer[20] = "Hello World!";
        char expected[20] = "Hello World!";

        ft_bzero(buffer, 12);
        memset(expected, 0, 12);
        ASSERT_PRINT_EQUAL("Test 5: ft_bzero(buffer, 12)", memcmp(buffer, expected, 20), 0);
    }

    printf("ft_bzero completed successfully.\n\n");
}

/*
    0 size is not tested because malloc behaviour is implementation defined, it call return NULL or ptr
*/
void ft_calloc_test()
{
    printf("ft_calloc started:\n");

    {
        size_t num = 5, size = sizeof(int);
        int *result = (int *)ft_calloc(num, size);
        int expected[5] = {0, 0, 0, 0, 0};

        ASSERT_PRINT_EQUAL("Test 1: ft_calloc(5, sizeof(int))", memcmp(result, expected, num * size), 0);
        free(result);
    }

    {
        size_t num = 10, size = sizeof(char);
        char *result = (char *)ft_calloc(num, size);
        char expected[10] = {0};

        ASSERT_PRINT_EQUAL("Test 2: ft_calloc(10, sizeof(char))", memcmp(result, expected, num * size), 0);
        free(result);
    }

    {
        size_t num = 1, size = sizeof(long);
        long *result = (long *)ft_calloc(num, size);
        long expected = 0;

        ASSERT_PRINT_EQUAL("Test 3: ft_calloc(1, sizeof(long)) == zeroed memory", memcmp(result, &expected, size), 0);
        free(result);
    }

    printf("ft_calloc completed successfully.\n\n");
}

void ft_memcmp_test()
{
    printf("ft_memcmp started:\n");

    {
        char str1[] = "abcdef";
        char str2[] = "abcdef";

        ASSERT_PRINT_EQUAL("Test 1: Identical strings",
                           ft_memcmp(str1, str2, 6), memcmp(str1, str2, 6));
    }

    {
        char str1[] = "abcdeg";
        char str2[] = "abcdef";

        ASSERT_PRINT_EQUAL("Test 2: Difference at last character",
                           ft_memcmp(str1, str2, 6), memcmp(str1, str2, 6));
    }

    {
        char str1[] = "abcd";
        char str2[] = "abcf";

        ASSERT_PRINT_EQUAL("Test 3: Difference in middle",
                           ft_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
    }

    {
        char str1[] = "Hello";
        char str2[] = "World";

        ASSERT_PRINT_EQUAL("Test 4: Completely different strings",
                           ft_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
    }

    {
        char str1[] = "";
        char str2[] = "";

        ASSERT_PRINT_EQUAL("Test 5: Both strings empty",
                           ft_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
    }

    {
        char str1[] = "abc\0def";
        char str2[] = "abc\0xyz";

        ASSERT_PRINT_EQUAL("Test 6: Strings with null bytes",
                           ft_memcmp(str1, str2, 7), memcmp(str1, str2, 7));
    }

    {
        char str1[] = {0, 1, 2, 3, 4, 5};
        char str2[] = {0, 1, 2, 3, 4, 5};

        ASSERT_PRINT_EQUAL("Test 7: Binary data identical",
                           ft_memcmp(str1, str2, 6), memcmp(str1, str2, 6));
    }

    {
        char str1[] = {0, 1, 2, 3, 4, 5};
        char str2[] = {0, 1, 2, 3, 4, 6};

        ASSERT_PRINT_EQUAL("Test 8: Binary data different",
                           ft_memcmp(str1, str2, 6), memcmp(str1, str2, 6));
    }

    {
        char str1[] = "abcdef";
        char str2[] = "abcxyz";

        ASSERT_PRINT_EQUAL("Test 9: Partial comparison",
                           ft_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
    }

    printf("ft_memcmp completed successfully.\n\n");
}
