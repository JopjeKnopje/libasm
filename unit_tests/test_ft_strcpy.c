#include "libasm.h"
#include <stddef.h>
#include <string.h>
#include <strings.h>
#include "unity.h"



void test_copy()
{
	size_t SIZE = 32;
	const char *src = "123";
	char dst[SIZE];
	bzero(dst, SIZE * sizeof(char));

	char *s = ft_strcpy(dst, src);

	TEST_ASSERT_EQUAL_PTR_MESSAGE(&dst, s, "return value is not equal to dst pointer");
	TEST_ASSERT_EQUAL_CHAR_ARRAY(src, dst, strlen(src));
	printf("%s\n", dst);
}
