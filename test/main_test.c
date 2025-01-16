#include "test.h"

int main()
{
    // string
    ft_strlen_test();
    ft_strcpy_test();
    ft_strcmp_test();
    ft_strdup_test();

    // syscall
    ft_write_test();
    ft_read_test();

    // char
    ft_tolower_test();
    ft_toupper_test();
    ft_isspace_test();
    ft_isprint_test();
    ft_isdigit_test();
    ft_isascii_test();
    ft_isalpha_test();
    ft_isalnum_test();

    // mem
    ft_bzero_test();
    ft_calloc_test();
    ft_memcmp_test();

    return 0;
}