#include "libasm.h"
#include "unity.h"
#include <asm-generic/errno-base.h>
#include <errno.h>
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define OK (0)

// void test_malloc_fail(void)
// {
// 	// make sure errno is not set
//     TEST_ASSERT_EQUAL_INT32_MESSAGE(OK, errno, "errno is already set to [%s]", strerror(errno));
//
//     void *ptr = ft_malloc_wrap(PTRDIFF_MAX);
// 	(void) ptr;
//     // 1. check if `errno` has been set by our function.
//     TEST_ASSERT_EQUAL_INT32_MESSAGE(ENOMEM, errno, "expected errno [%s] got [%s]",
//     strerror(ENOMEM), strerror(errno));
//
// }

// TODO: Figure out how to monitor malloced size
void test_malloc_info()
{
    char *test = strdup("test123");
    char *s = ft_strdup(test);
    int64_t x = (int64_t)s;

    printf("[%s]\n", s);
    printf("%ld\n", x);

    // void *x = (int32_t *) s;
    //
    // printf("%u\n", (int32_t) x);

    // s[2100] = 't';
    (void)s;
}
