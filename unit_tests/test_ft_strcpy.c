#include "libasm.h"
#include "unity.h"
#include <stddef.h>
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
    printf("%s\n", dst);
}

void test_copy_overflow()
{
    size_t SIZE = 1;
    const char *src = "123";
    char dst[SIZE];

    char *s = ft_strcpy(dst, src);

    TEST_ASSERT_EQUAL_PTR_MESSAGE(&dst, s, "return value is not equal to dst pointer");
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(src, dst, strlen(src), "overflow failed");
}
