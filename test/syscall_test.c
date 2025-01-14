#include "test.h"

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