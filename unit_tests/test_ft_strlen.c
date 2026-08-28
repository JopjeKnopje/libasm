#include "libasm.h"
#include "string.h"
#include "unity.h"

void test_valid_string(void)
{
    char *s = "1";

    int expected = strlen(s);
    int actual = ft_strlen(s);

    TEST_ASSERT_EQUAL_INT32_MESSAGE(expected, actual, "output values don't match");
}
