#include "libasm.h"
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "unity.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_should_doBlahAndBlah(void) {
	const char *s = "teststring123";
	const ssize_t s_len = strlen(s);

    ssize_t res = ft_write(1, s, s_len);
	(void) res;
    // cr_assert(res == s_len, "Got result: %ld\n", res);
}


// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_should_doBlahAndBlah);
    return UNITY_END();
}
