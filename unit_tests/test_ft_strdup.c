#include "big_str.h"
#include "libasm.h"
#include "unity.h"
#include <stdint.h>
#include <string.h>

void test_strdup_check_len()
{
    char *test = "test123";
    char *s = ft_strdup(test);

    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_INT32_MESSAGE(strlen(s), strlen(test),
                                    "output string length does not match input");
}

void test_strdup_big_str()
{
    char *test = BIG_STR;
    char *s = ft_strdup(test);

    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_INT32_MESSAGE(strlen(s), strlen(test),
                                    "output string length does not match input");
}

void test_strdup_empty()
{
    char *test = "";
    char *s = ft_strdup(test);

    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_INT32_MESSAGE(strlen(s), strlen(test),
                                    "output string length does not match input");
}

void test_strdup_terminated()
{
    char *test = "part\0ofastring";
    char *s = ft_strdup(test);

    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_INT32_MESSAGE(strlen(s), strlen(test),
                                    "output string length does not match input");
}
