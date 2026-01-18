#include "libasm.h"
#include <criterion/criterion.h>
#include <criterion/hooks.h>
#include <criterion/internal/assert.h>
#include <criterion/types.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#define OurTest(...) Test(ft_strlen, ...);

Test(ft_strlen, strlen_slen)
{
	const char *s = "teststring123";
	const ssize_t s_len = strlen(s);

    ssize_t res = ft_write(1, s, s_len);
    cr_assert(res == s_len, "Got result: %ld\n", res);
}
