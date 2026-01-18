#include "libasm.h"
#include "unity.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

#define POEP(threshold, actual, messag, ...)                                                       \
    char msg[256];                                                                                 \
    sprintf(msg, messag, ...);                                                                     \
    TEST_ASSERT_GREATER_THAN_INT32_MESSAGE(threshold, actual, msg)
#define MAX(a, b) ((a) > (b)) ? (a) : (b)

int fd;

void setUp(void)
{
    // set stuff up here
    char name[] = "/tmp/fileXXXXXX";
    fd = mkstemp(name);
    TEST_PRINTF("temp file [%s]\n", name);
    char msg[256] = {0};
    sprintf(msg, "failed creating tempfile: [%s]\n", strerror(errno));
    TEST_ASSERT_GREATER_THAN_INT32_MESSAGE(0, fd, msg);
}

void tearDown(void)
{
    int res = close(fd);
    TEST_ASSERT_NOT_EQUAL_INT32_MESSAGE(-1, res, "failed closing tempfile");
}

// parameters
// zero length
// size_t max
// invalid fd
// write partitial string

void test_print_check_written_len(void)
{
    const char *s = "teststring123";
    const ssize_t s_len = strlen(s);
    const int old_err = errno;

    ssize_t bytes_written = ft_write(fd, s, s_len);
    // check if written bytes match.
    TEST_ASSERT_EQUAL_INT64(s_len, bytes_written);

    // check if errno has not been set by our function.
    char buf[256] = {0};
    sprintf(buf, "Errno: set to [%s]\n", strerror(errno));
    TEST_ASSERT_EQUAL_INT64_MESSAGE(old_err, errno, buf);

    char file_content[256] = {0};
    lseek(fd, -s_len, SEEK_CUR);
    ssize_t file_content_len = read(fd, file_content, s_len);
    char msg[256] = {0};
    sprintf(msg, "failed reading file: [%s]\n", strerror(errno));
    TEST_ASSERT_GREATER_THAN_INT32_MESSAGE(0, file_content_len, msg);

    TEST_ASSERT_EQUAL_INT64(s_len, file_content_len);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(s, file_content, s_len);
}
