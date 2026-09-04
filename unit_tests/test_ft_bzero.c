#include "libasm.h"
#include "unity.h"
#include <string.h>

void test_bzero()
{
    char s[] = "12345xxxxx";
    size_t len = 5;

    ft_bzero(s, len);

    TEST_ASSERT_MESSAGE(s[0] == 0, "first array entry not cleared");
    TEST_ASSERT_MESSAGE(s[len - 1] == 0, "last array entry not cleared");
    TEST_ASSERT_MESSAGE(s[len] != 0, "out of bounds, should be untouched");
}
