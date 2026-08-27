#include "libasm.h"
#include "unity.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <threads.h>
#include <unistd.h>

int fd;

char *FILE_CONTENT = "some-text";

void setUp(void)
{
    // set stuff up here
    char name[] = "/tmp/fileXXXXXX";
    fd = mkstemp(name);
    write(fd, FILE_CONTENT, strlen(FILE_CONTENT));
    lseek(fd, SEEK_SET, 0);

    // TEST_PRINTF("created temp file [%s]", name);
    TEST_ASSERT_GREATER_THAN_INT32_MESSAGE(0, fd, "failed creating tempfile: [%s]",
                                           strerror(errno));
}

void tearDown(void)
{
    int res = close(fd);
    TEST_ASSERT_NOT_EQUAL_INT32_MESSAGE(-1, res, "failed closing tempfile: [%s]", strerror(errno));
}

void test_read_check_general(void)
{
    size_t bufsize = 32;
    char s[bufsize];
    bzero(s, bufsize * sizeof(char));
    const int old_err = errno;

    ssize_t bytes_read = ft_read(fd, s, bufsize);
    // check if read bytes equal
    TEST_ASSERT_EQUAL_INT64(strlen(FILE_CONTENT), bytes_read);

    // 2. check if `errno` has not been set by our function.
    TEST_ASSERT_EQUAL_INT32_MESSAGE(old_err, errno, "errno set to [%s]", strerror(errno));

    TEST_ASSERT_EQUAL_CHAR_ARRAY(s, FILE_CONTENT, bytes_read);
}

void test_zero_length()
{
    const char *s = "";
    const int old_err = errno;

    ssize_t bytes_written = ft_read(fd, s, 0);

    TEST_ASSERT_EQUAL_INT32_MESSAGE(old_err, errno, "errno set to [%s]", strerror(errno));
    TEST_ASSERT_EQUAL_INT64(0, bytes_written);
}

void test_invalid_fd_return_val()
{
    const char *s = "test_string";
    const ssize_t s_len = strlen(s);

    ssize_t bytes_written = ft_read(-1, s, s_len);

    TEST_ASSERT_EQUAL_INT64(-1, bytes_written);
}

void test_null_ptr_string()
{
    const char *s = "test_string";
    const ssize_t s_len = strlen(s);

    ssize_t bytes_written = ft_read(-1, NULL, s_len);

    TEST_ASSERT_EQUAL_INT64(-1, bytes_written);
}

void test_invalid_fd_errno()
{
    const char *s = "test_string";
    const ssize_t s_len = strlen(s);

    ft_read(-1, s, s_len);

    const size_t expected_errno = 9;
    TEST_ASSERT_EQUAL_INT32_MESSAGE(expected_errno, errno, "[%s] [%s]", strerror(expected_errno),
                                    strerror(errno));
}
