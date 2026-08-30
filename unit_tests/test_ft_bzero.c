#include "libasm.h"
#include "unity.h"
#include <string.h>

void test_bzero()
{
    char s[] = "test123";
    size_t len = strlen(s);

    ft_bzero(s, len);

    TEST_ASSERT_MESSAGE(s[0] == 0, "first array entry not cleared");
    TEST_ASSERT_MESSAGE(s[len] == 0, "last array entry not cleared");
}
