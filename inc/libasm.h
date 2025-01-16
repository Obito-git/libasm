#ifndef LIBASM_H
#define LIBASM_H

#include <unistd.h>

size_t ft_strlen(const char *str);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *src);

// char
int ft_tolower(int c);
int ft_toupper(int c);
int ft_isspace(int c);
int ft_isprint(int c);
int ft_isdigit(int c);
int ft_isascii(int c);
int ft_isalpha(int c);
int ft_isalnum(int c);

// mem
void ft_bzero(void *mem, size_t n);
void *ft_calloc(size_t nmemb, size_t size);
int ft_memcmp(const void *str1, const void *str2, size_t n);

#endif