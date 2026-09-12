#include "libasm.h"
#include "unity.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

void test_copy()
{
    size_t SIZE = 32;
    const char *src = "test123";
    char dst[SIZE];
    bzero(dst, SIZE * sizeof(char));

    char *s = ft_strcpy(dst, src);

    TEST_ASSERT_EQUAL_PTR_MESSAGE(&dst, s, "return value is not equal to dst pointer");
    TEST_ASSERT_EQUAL_CHAR_ARRAY(src, dst, strlen(src));
}

void test_copy_null_term()
{
    const char *src = "test123";
    size_t SIZE = ft_strlen(src);
    // size of our memory area for testing
    size_t DST_SIZE = SIZE + 8;
    char dst[DST_SIZE];

    // zero our array, and set it to a non-zero character, that way we can check if it has been
    // NULL-terminated later on
    bzero(dst, DST_SIZE);
    memset(dst, '=', DST_SIZE - 1);

    char *s = ft_strcpy(dst, src);

    TEST_ASSERT_EQUAL_PTR_MESSAGE(&dst, s, "return value is not equal to dst pointer");
    TEST_ASSERT_EQUAL_CHAR_MESSAGE(0, dst[SIZE], "NULL terminator not set");
}

void test_copy_overflow()
{
    size_t SIZE = 1;
    const char *src = "test123";
    char dst[SIZE];

    char *s = ft_strcpy(dst, src);

    TEST_ASSERT_EQUAL_PTR_MESSAGE(&dst, s, "return value is not equal to dst pointer");
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(src, dst, strlen(src), "overflow failed");
}
