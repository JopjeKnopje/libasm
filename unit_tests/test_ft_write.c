#include "libasm.h"
#include <criterion/criterion.h>
#include <criterion/hooks.h>
#include <criterion/internal/assert.h>
#include <criterion/types.h>
#include <stdint.h>


Test(ft_write, write)
{
    int64_t res = ft_strlen();
    cr_assert(res == 2147483648, "Got result: %ld\n", res);
}

