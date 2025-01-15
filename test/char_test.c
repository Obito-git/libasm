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

/*
    Standart isspace doesn't return 1 for true but 8192 on my system for some reason.
    Thats why I don't compare mine with the real one
*/
void ft_isspace_test()
{
    printf("ft_isspace started:\n");

    {
        char c = ' ';
        ASSERT_PRINT_EQUAL("Test 1: ft_isspace(' ') == 1", ft_isspace(c), 1);
    }

    {
        char c = '\t';
        ASSERT_PRINT_EQUAL("Test 2: ft_isspace('\\t') == 1", ft_isspace(c), 1);
    }

    {
        char c = '\n';
        ASSERT_PRINT_EQUAL("Test 3: ft_isspace('\\n') == 1", ft_isspace(c), 1);
    }

    {
        char c = 'A';
        ASSERT_PRINT_EQUAL("Test 4: ft_isspace('A') == 0", ft_isspace(c), 0);
    }

    {
        char c = '1';
        ASSERT_PRINT_EQUAL("Test 5: ft_isspace('1') == 0", ft_isspace(c), 0);
    }

    {
        char c = '\v';
        ASSERT_PRINT_EQUAL("Test 6: ft_isspace('\\v') == 1", ft_isspace(c), 1);
    }

    printf("ft_isspace completed successfully.\n\n");
}

/*
    Standard isprint doesn't return 1 for true but a non-zero value (like 16384) on my system.
    That's why I don't compare mine with the real one, but check for 1 or 0 directly.
*/
void ft_isprint_test()
{
    printf("ft_isprint started:\n");

    {
        int c = 'A';
        ASSERT_PRINT_EQUAL("Test 1: ft_isprint('A') == 1", ft_isprint(c), 1);
    }

    {
        int c = ' ';
        ASSERT_PRINT_EQUAL("Test 2: ft_isprint(' ') == 1", ft_isprint(c), 1);
    }

    {
        int c = '5';
        ASSERT_PRINT_EQUAL("Test 3: ft_isprint('5') == 1", ft_isprint(c), 1);
    }

    {
        int c = '\n';
        ASSERT_PRINT_EQUAL("Test 4: ft_isprint('\\n') == 0", ft_isprint(c), 0);
    }

    {
        int c = '\t';
        ASSERT_PRINT_EQUAL("Test 5: ft_isprint('\\t') == 0", ft_isprint(c), 0);
    }

    {
        int c = 127;
        ASSERT_PRINT_EQUAL("Test 6: ft_isprint(127) == 0", ft_isprint(c), 0);
    }

    {
        int c = 31;
        ASSERT_PRINT_EQUAL("Test 7: ft_isprint(31) == 0", ft_isprint(c), 0);
    }

    {
        int c = 128;
        ASSERT_PRINT_EQUAL("Test 8: ft_isprint(128) == 0", ft_isprint(c), 0);
    }

    {
        int c = '\v';
        ASSERT_PRINT_EQUAL("Test 9: ft_isprint('\\v') == 0", ft_isprint(c), 0);
    }

    {
        int c = '\r';
        ASSERT_PRINT_EQUAL("Test 10: ft_isprint('\\r') == 0", ft_isprint(c), 0);
    }

    printf("ft_isprint completed successfully.\n\n");
}

/*
    Standard isdigit doesn't return 1 for true but a non-zero value (like 2048) on my system.
    That's why I don't compare mine with the real one, but check for 1 or 0 directly.
*/
void ft_isdigit_test()
{
    printf("ft_isdigit started:\n");

    {
        int c = '0';
        ASSERT_PRINT_EQUAL("Test 1: ft_isdigit('0') == 1", ft_isdigit(c), 1);
    }

    {
        int c = '5';
        ASSERT_PRINT_EQUAL("Test 2: ft_isdigit('5') == 1", ft_isdigit(c), 1);
    }

    {
        int c = '9';
        ASSERT_PRINT_EQUAL("Test 3: ft_isdigit('9') == 1", ft_isdigit(c), 1);
    }

    {
        int c = 'A';
        ASSERT_PRINT_EQUAL("Test 4: ft_isdigit('A') == 0", ft_isdigit(c), 0);
    }

    {
        int c = ' ';
        ASSERT_PRINT_EQUAL("Test 5: ft_isdigit(' ') == 0", ft_isdigit(c), 0);
    }

    {
        int c = '\n';
        ASSERT_PRINT_EQUAL("Test 6: ft_isdigit('\\n') == 0", ft_isdigit(c), 0);
    }

    {
        int c = '$';
        ASSERT_PRINT_EQUAL("Test 7: ft_isdigit('$') == 0", ft_isdigit(c), 0);
    }

    {
        int c = 128;
        ASSERT_PRINT_EQUAL("Test 8: ft_isdigit(128) == 0", ft_isdigit(c), 0);
    }

    printf("ft_isdigit completed successfully.\n\n");
}

/*
    Standard isascii doesn't return 1 for true but a non-zero value (like 1 or 1024) on my system.
    That's why I don't compare mine with the real one, but check for 1 or 0 directly.
*/
void ft_isascii_test()
{
    printf("ft_isascii started:\n");

    {
        int c = 0;
        ASSERT_PRINT_EQUAL("Test 1: ft_isascii(0) == 1", ft_isascii(c), 1);
    }

    {
        int c = 'A';
        ASSERT_PRINT_EQUAL("Test 2: ft_isascii('A') == 1", ft_isascii(c), 1);
    }

    {
        int c = 127;
        ASSERT_PRINT_EQUAL("Test 3: ft_isascii(127) == 1", ft_isascii(c), 1);
    }

    {
        int c = 128;
        ASSERT_PRINT_EQUAL("Test 4: ft_isascii(128) == 0", ft_isascii(c), 0);
    }

    {
        int c = -1;
        ASSERT_PRINT_EQUAL("Test 5: ft_isascii(-1) == 0", ft_isascii(c), 0);
    }

    {
        int c = ' ';
        ASSERT_PRINT_EQUAL("Test 6: ft_isascii(' ') == 1", ft_isascii(c), 1);
    }

    {
        int c = '\n';
        ASSERT_PRINT_EQUAL("Test 7: ft_isascii('\\n') == 1", ft_isascii(c), 1);
    }

    {
        int c = 255;
        ASSERT_PRINT_EQUAL("Test 8: ft_isascii(255) == 0", ft_isascii(c), 0);
    }

    printf("ft_isascii completed successfully.\n\n");
}

/*
    Standard isalpha doesn't return 1 for true but a non-zero value (like 1024) on my system.
    That's why I don't compare mine with the real one, but check for 1 or 0 directly.
*/
void ft_isalpha_test()
{
    printf("ft_isalpha started:\n");

    {
        int c = 'A';
        ASSERT_PRINT_EQUAL("Test 1: ft_isalpha('A') == 1", ft_isalpha(c), 1);
    }

    {
        int c = 'Z';
        ASSERT_PRINT_EQUAL("Test 2: ft_isalpha('Z') == 1", ft_isalpha(c), 1);
    }

    {
        int c = 'a';
        ASSERT_PRINT_EQUAL("Test 3: ft_isalpha('a') == 1", ft_isalpha(c), 1);
    }

    {
        int c = 'z';
        ASSERT_PRINT_EQUAL("Test 4: ft_isalpha('z') == 1", ft_isalpha(c), 1);
    }

    {
        int c = '5';
        ASSERT_PRINT_EQUAL("Test 5: ft_isalpha('5') == 0", ft_isalpha(c), 0);
    }

    {
        int c = ' ';
        ASSERT_PRINT_EQUAL("Test 6: ft_isalpha(' ') == 0", ft_isalpha(c), 0);
    }

    {
        int c = '$';
        ASSERT_PRINT_EQUAL("Test 7: ft_isalpha('$') == 0", ft_isalpha(c), 0);
    }

    {
        int c = 128;
        ASSERT_PRINT_EQUAL("Test 8: ft_isalpha(128) == 0", ft_isalpha(c), 0);
    }

    printf("ft_isalpha completed successfully.\n\n");
}

/*
    Standard isalnum doesn't return 1 for true but a non-zero value (like 8) on my system.
    That's why I don't compare mine with the real one, but check for 1 or 0 directly.
*/
void ft_isalnum_test()
{
    printf("ft_isalnum started:\n");

    {
        int c = 'A';
        ASSERT_PRINT_EQUAL("Test 1: ft_isalnum('A') == 1", ft_isalnum(c), 1);
    }

    {
        int c = 'Z';
        ASSERT_PRINT_EQUAL("Test 2: ft_isalnum('Z') == 1", ft_isalnum(c), 1);
    }

    {
        int c = 'a';
        ASSERT_PRINT_EQUAL("Test 3: ft_isalnum('a') == 1", ft_isalnum(c), 1);
    }

    {
        int c = 'z';
        ASSERT_PRINT_EQUAL("Test 4: ft_isalnum('z') == 1", ft_isalnum(c), 1);
    }

    {
        int c = '0';
        ASSERT_PRINT_EQUAL("Test 5: ft_isalnum('0') == 1", ft_isalnum(c), 1);
    }

    {
        int c = '9';
        ASSERT_PRINT_EQUAL("Test 6: ft_isalnum('9') == 1", ft_isalnum(c), 1);
    }

    {
        int c = ' ';
        ASSERT_PRINT_EQUAL("Test 7: ft_isalnum(' ') == 0", ft_isalnum(c), 0);
    }

    {
        int c = '$';
        ASSERT_PRINT_EQUAL("Test 8: ft_isalnum('$') == 0", ft_isalnum(c), 0);
    }

    {
        int c = 128;
        ASSERT_PRINT_EQUAL("Test 9: ft_isalnum(128) == 0", ft_isalnum(c), 0);
    }

    {
        int c = '\n';
        ASSERT_PRINT_EQUAL("Test 10: ft_isalnum('\\n') == 0", ft_isalnum(c), 0);
    }

    printf("ft_isalnum completed successfully.\n\n");
}
