#ifndef TEST_H
#define TEST_H

#include "assert.h"
#include "libasm.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

// syscall test
void ft_write_test();
void ft_read_test();

// string test
void ft_strlen_test();
void ft_strcpy_test();
void ft_strcmp_test();
void ft_strdup_test();

// char test
void ft_tolower_test();
void ft_toupper_test();
void ft_isspace_test();
void ft_isprint_test();
void ft_isdigit_test();
void ft_isascii_test();
void ft_isalpha_test();
void ft_isalnum_test();

// mem test
void ft_bzero_test();
void ft_calloc_test();
void ft_memcmp_test();
void ft_memcpy_test();

#endif