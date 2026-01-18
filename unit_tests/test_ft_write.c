#include "libasm.h"
#include "unity.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

int fd;

void setUp(void)
{
    // set stuff up here
    char name[] = "/tmp/fileXXXXXX";
    fd = mkstemp(name);
    // TEST_PRINTF("created temp file [%s]", name);
    TEST_ASSERT_GREATER_THAN_INT32_MESSAGE(0, fd, "failed creating tempfile: [%s]",
                                           strerror(errno));
}

void tearDown(void)
{
    int res = close(fd);
    TEST_ASSERT_NOT_EQUAL_INT32_MESSAGE(-1, res, "failed closing tempfile: [%s]", strerror(errno));
}

// parameters
// zero length
// size_t max
// invalid fd
// write partitial string

void test_write_check_general(void)
{
    const char *s = "teststring123";
    const ssize_t s_len = strlen(s);
    const int old_err = errno;

    ssize_t bytes_written = ft_write(fd, s, s_len);
    // 1. check if written bytes match
    TEST_ASSERT_EQUAL_INT64(s_len, bytes_written);

    // 2. check if `errno` has not been set by our function.
    TEST_ASSERT_EQUAL_INT32_MESSAGE(old_err, errno, "errno set to [%s]", strerror(errno));

    char file_content[64] = {0};
    lseek(fd, -s_len, SEEK_CUR);
    ssize_t file_content_len = read(fd, file_content, s_len);
    // check if we managed to read the file
    TEST_ASSERT_GREATER_THAN_INT64_MESSAGE(0, file_content_len, "failed reading file: [%s]",
                                           strerror(errno));

    // 3. check that the read bytes is the name as the written string len
    TEST_ASSERT_EQUAL_INT64(s_len, file_content_len);
    // 4. check if the file content matches the intput string
    TEST_ASSERT_EQUAL_CHAR_ARRAY(s, file_content, s_len);
}

void test_zero_length()
{
    const char *s = "";
    const int old_err = errno;

    ssize_t bytes_written = ft_write(fd, s, 0);

    TEST_ASSERT_EQUAL_INT32_MESSAGE(old_err, errno, "errno set to [%s]", strerror(errno));
    TEST_ASSERT_EQUAL_INT64(0, bytes_written);
}

void test_invalid_fd_return_val()
{
    const char *s = "test_string";
    const ssize_t s_len = strlen(s);

    ssize_t bytes_written = ft_write(-1, s, s_len);

    TEST_ASSERT_EQUAL_INT64(-1, bytes_written);
}

void test_invalid_fd_errno()
{
    const char *s = "test_string";
    const ssize_t s_len = strlen(s);

    ft_write(-1, s, s_len);

    const size_t expected_errno = 9;
    TEST_ASSERT_EQUAL_INT32_MESSAGE(expected_errno, errno, "[%s] [%s]", strerror(expected_errno),
                                    strerror(errno));
}
