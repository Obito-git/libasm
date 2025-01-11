#include "assert.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern size_t ft_strlen(const char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *src);

void ft_strlen_test()
{
    printf("ft_strlen_test started:\n");

    {
        char *str1 = "";
        ASSERT_PRINT_EQUAL("Test 1: ft_strlen with empty string",
                           ft_strlen(str1), strlen(str1));
    }

    {
        char *str2 = "Hello world\n";
        ASSERT_PRINT_EQUAL("Test 2: ft_strlen with 'Hello world\\n'",
                           ft_strlen(str2), strlen(str2));
    }

    {
        char *str3 = "0000IDK not actually hard toto titi lala what else can be here -_-";
        ASSERT_PRINT_EQUAL("Test 3: ft_strlen with a longer string",
                           ft_strlen(str3), strlen(str3));
    }

    printf("ft_strlen_test completed successfully.\n\n");
}

void ft_strcpy_test()
{
    printf("ft_strcpy_test started:\n");

    {
        char *from1 = "123";
        char to1[] = "000456";
        char to2[] = "000456";
        ASSERT_PRINT_EQUAL("Test 1: ft_strcpy normal string copy",
                           ft_strcpy(to1, from1), strcpy(to2, from1));
    }

    {
        char *from2 = "";
        char to3[] = "abcdef";
        char to4[] = "abcdef";
        ASSERT_PRINT_EQUAL("Test 2: ft_strcpy empty string",
                           ft_strcpy(to3, from2), strcpy(to4, from2));
    }

    {
        char *from3 = "This is a longer test string to check the behavior of ft_strcpy.";
        char to5[100];
        char to6[100];
        ASSERT_PRINT_EQUAL("Test 3: ft_strcpy with a longer string",
                           ft_strcpy(to5, from3), strcpy(to6, from3));
    }

    printf("ft_strcpy_test completed successfully.\n\n");
}

void ft_strcmp_test()
{
    printf("ft_strcmp_test started:\n");

    {
        char *s1 = "Hello world";
        char *s2 = "Hello world";
        ASSERT_PRINT_EQUAL("Test 1: Identical strings",
                           ft_strcmp(s1, s2), strcmp(s1, s2));
    }

    {
        char *s3 = "Hello";
        char *s4 = "Hello world";
        ASSERT_PRINT_EQUAL("Test 2: s1 < s2",
                           ft_strcmp(s3, s4), strcmp(s3, s4));
    }

    {
        char *s5 = "Hello worldz";
        char *s6 = "Hello world";
        ASSERT_PRINT_EQUAL("Test 3: s1 > s2",
                           ft_strcmp(s5, s6), strcmp(s5, s6));
    }

    {
        char *s7 = "";
        char *s8 = "Hello";
        ASSERT_PRINT_EQUAL("Test 4: empty vs non-empty",
                           ft_strcmp(s7, s8), strcmp(s7, s8));
    }

    {
        char *s9 = "";
        char *s10 = "";
        ASSERT_PRINT_EQUAL("Test 5: both empty",
                           ft_strcmp(s9, s10), strcmp(s9, s10));
    }

    printf("ft_strcmp_test completed successfully.\n\n");
}

void ft_write_test()
{
    printf("ft_write_test started:\n");

    {
        const char *msg = "Hello world\n";
        errno = 0;
        ssize_t ret = ft_write(STDOUT_FILENO, msg, strlen(msg));
        ASSERT_PRINT_EQUAL("Test 1: write to STDOUT", strlen(msg), ret);
        ASSERT_ERRNO(0, "Test 1: errno should remain 0 for successful writes");
    }

    {
        errno = 0;
        ssize_t ret = ft_write(-1, "Should fail\n", 12);
        ASSERT_PRINT_EQUAL("Test 2: invalid FD", -1, ret);
        ASSERT_ERRNO(EBADF, "Test 2: errno should be EBADF for invalid FD");
    }

    {
        errno = 0;
        ssize_t ret = ft_write(STDOUT_FILENO, "Hello world\n", 0);
        ASSERT_PRINT_EQUAL("Test 3: zero-length write", 0, ret);
        ASSERT_ERRNO(0, "Test 3: errno should remain 0 for zero-length writes");
    }

    printf("ft_write_test completed successfully.\n\n");
}

void ft_read_test()
{
    printf("ft_read_test started:\n");

    {
        const char *test_data = "Hello, ft_read!\n";
        char buffer[50];
        ssize_t ret;
        int pipe_fds[2];

        if (pipe(pipe_fds) == -1)
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }

        ssize_t write_ret = write(pipe_fds[1], test_data, strlen(test_data));
        if (write_ret == -1)
        {
            perror("write to pipe");
            close(pipe_fds[0]);
            close(pipe_fds[1]);
            exit(EXIT_FAILURE);
        }

        close(pipe_fds[1]);

        memset(buffer, 0, sizeof(buffer));
        errno = 0;

        ret = ft_read(pipe_fds[0], buffer, sizeof(buffer) - 1);

        ASSERT_PRINT_EQUAL("Test 1: Successful read from pipe", strlen(test_data), ret);
        ASSERT_ERRNO(0, "Test 1: errno should remain 0 for successful reads");

        ASSERT_PRINT_EQUAL("Test 1: Read data matches written data", 0, strcmp(buffer, test_data));

        close(pipe_fds[0]);
    }

    {
        char buffer[10];
        ssize_t ret;

        errno = 0;

        ret = ft_read(-1, buffer, sizeof(buffer));

        ASSERT_PRINT_EQUAL("Test 2: Read from invalid FD", -1, ret);
        ASSERT_ERRNO(EBADF, "Test 2: errno should be EBADF for invalid FD");
    }

    {
        char buffer[10];
        ssize_t ret;

        errno = 0;

        ret = ft_read(STDIN_FILENO, buffer, 0);

        ASSERT_PRINT_EQUAL("Test 3: Zero-length read", 0, ret);
        ASSERT_ERRNO(0, "Test 3: errno should remain 0 for zero-length reads");
    }

    printf("ft_read_test completed successfully.\n\n");
}

void ft_strdup_test()
{
    printf("ft_strdup_test started:\n");

    {
        char *src = "Hello world";
        char *dup = ft_strdup(src);
        ASSERT_PRINT_EQUAL("Test 1: Normal string duplication", 0, strcmp(dup, src));
        free(dup);
    }

    {
        char *src = "";
        char *dup = ft_strdup(src);
        ASSERT_PRINT_EQUAL("Test 2: Empty string duplication", 0, strcmp(dup, src));
        free(dup);
    }

    {
        char *src = "This is a much longer string to test ft_strdup for larger inputs.";
        char *dup = ft_strdup(src);
        ASSERT_PRINT_EQUAL("Test 3: Long string duplication", 0, strcmp(dup, src));
        free(dup);
    }

    {
        char *src = "Hello\tWorld\n123!@#";
        char *dup = ft_strdup(src);
        ASSERT_PRINT_EQUAL("Test 4: String with special characters", 0, strcmp(dup, src));
        free(dup);
    }

    {
        char *dup = ft_strdup(NULL);
        if (dup != NULL)
        {
            fprintf(stderr, "[FAIL] Test 5: Should be NULL\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            fprintf(stderr, "[PASS] Test 5: Should be NULL\n");
        }
    }

    {
        char *src = "A";
        char *dup = ft_strdup(src);
        ASSERT_PRINT_EQUAL("Test 6: Single character string duplication", 0, strcmp(dup, src));
        free(dup);
    }

    printf("ft_strdup_test completed successfully.\n\n");
}

int main()
{
    ft_strlen_test();
    ft_strcpy_test();
    ft_strcmp_test();
    ft_write_test();
    ft_read_test();
    ft_strdup_test();

    return 0;
}
