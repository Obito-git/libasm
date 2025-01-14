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