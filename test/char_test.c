#include "test.h"

void ft_tolower_test()
{
    printf("ft_tolower started:\n");

    {
        int c = 'A';
        ASSERT_PRINT_EQUAL("Test 1: ", ft_tolower(c), tolower(c));
    }

    {
        int c = 'Z';
        ASSERT_PRINT_EQUAL("Test 2: ", ft_tolower(c), tolower(c));
    }

    {
        int c = 'a';
        ASSERT_PRINT_EQUAL("Test 3: ", ft_tolower(c), tolower(c));
    }

    {
        int c = '5';
        ASSERT_PRINT_EQUAL("Test 4: ", ft_tolower(c), tolower(c));
    }

    {
        int c = '$';
        ASSERT_PRINT_EQUAL("Test 5: ", ft_tolower(c), tolower(c));
    }

    {
        int c = 128;
        ASSERT_PRINT_EQUAL("Test 6: ", ft_tolower(c), tolower(c));
    }

    printf("ft_tolower completed successfully.\n\n");
}

void ft_toupper_test()
{
    printf("ft_toupper started:\n");

    {
        int c = 'A';
        ASSERT_PRINT_EQUAL("Test 1: ", ft_toupper(c), toupper(c));
    }

    {
        int c = 'Z';
        ASSERT_PRINT_EQUAL("Test 2: ", ft_toupper(c), toupper(c));
    }

    {
        int c = 'a';
        ASSERT_PRINT_EQUAL("Test 3: ", ft_toupper(c), toupper(c));
    }

    {
        int c = '5';
        ASSERT_PRINT_EQUAL("Test 4: ", ft_toupper(c), toupper(c));
    }

    {
        int c = '$';
        ASSERT_PRINT_EQUAL("Test 5: ", ft_toupper(c), toupper(c));
    }

    {
        int c = 128;
        ASSERT_PRINT_EQUAL("Test 6: ", ft_toupper(c), toupper(c));
    }

    printf("ft_toupper completed successfully.\n\n");
}

void ft_isspace_test()
{
    printf("ft_isspace started:\n");

    {
        char c = ' ';
        ASSERT_PRINT_EQUAL("Test 1: ft_isspace(' ') == isspace(' ')", ft_isspace(c), isspace(c));
    }

    {
        char c = '\t';
        ASSERT_PRINT_EQUAL("Test 2: ft_isspace('\\t') == isspace('\\t')", ft_isspace(c), isspace(c));
    }

    {
        char c = '\n';
        ASSERT_PRINT_EQUAL("Test 3: ft_isspace('\\n') == isspace('\\n')", ft_isspace(c), isspace(c));
    }

    {
        char c = 'A';
        ASSERT_PRINT_EQUAL("Test 4: ft_isspace('A') == isspace('A')", ft_isspace(c), isspace(c));
    }

    {
        char c = '1';
        ASSERT_PRINT_EQUAL("Test 5: ft_isspace('1') == isspace('1')", ft_isspace(c), isspace(c));
    }

    {
        char c = '\v';
        ASSERT_PRINT_EQUAL("Test 6: ft_isspace('\\v') == isspace('\\v')", ft_isspace(c), isspace(c));
    }

    printf("ft_isspace completed successfully.\n\n");
}