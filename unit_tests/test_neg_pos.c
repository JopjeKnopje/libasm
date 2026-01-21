
#include "unity.h"
#include <stdint.h>

void setUp(void) {}

void tearDown(void) {}

int32_t invert_if_neg(int32_t val)
{
    if (val < 0)
        val *= -1;
    return val;
}

void test_pos()
{
    int32_t x = invert_if_neg(12);
    TEST_ASSERT_EQUAL_INT64(x, 12);
}

void test_neg()
{
    int32_t x = invert_if_neg(-12);
    TEST_ASSERT_EQUAL_INT64(x, 12);
}

void test_neg_max_int()
{
    int32_t x = invert_if_neg(INT32_MAX);
    TEST_ASSERT_EQUAL_INT64(INT32_MAX, x);

    // prevent overflow hihi
    x = invert_if_neg(INT32_MIN + 1);
    TEST_ASSERT_EQUAL_INT64(INT32_MAX, x);
}

int8_t bitwise_invert(int8_t x)
{
    x ^= 0b10000000;

    return x;
}

void test_int8_bitwise()
{
    int8_t x = bitwise_invert(0b11111111);
    TEST_ASSERT_EQUAL_INT8(127, x);
}
