#include "libasm.h"
#include "string.h"
#include "unity.h"

void test_valid_string(void)
{
    char *s = "test123";

    int expected = strlen(s);
    int actual = ft_strlen(s);

    TEST_ASSERT_EQUAL_INT32_MESSAGE(expected, actual, "output values don't match");
}

void test_null_string(void)
{
    char *s = NULL;

    // int expected = strlen(s);
    (void)ft_strlen(s);

    // TEST_ASSERT_EQUAL_INT32_MESSAGE(expected, actual, "output values don't match");
}
