#ifndef TEST_H
#define TEST_H

#include "assert.h"
#include "libasm.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

// Syscall test
void ft_write_test();
void ft_read_test();

// String test
void ft_strlen_test();
void ft_strcpy_test();
void ft_strcmp_test();
void ft_strdup_test();

// Char test
void ft_tolower_test();
void ft_toupper_test();
void ft_isspace_test();
void ft_isprint_test();
void ft_isdigit_test();
void ft_isascii_test();
void ft_isalpha_test();
void ft_isalnum_test();

#endif