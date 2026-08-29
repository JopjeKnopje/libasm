#include "libasm.h"
#include "string.h"
#include "unity.h"
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void test_valid_string(void)
{
    char *s = "test123";

    int expected = strlen(s);
    int actual = ft_strlen(s);

    TEST_ASSERT_EQUAL_INT32_MESSAGE(expected, actual, "output values don't match");
}

void test_null_should_crash(void)
{
    // char *s = NULL;

    // TODO: Fork and except segv

	int pid = fork();
	TEST_ASSERT_NOT_EQUAL_INT32_MESSAGE(-1, pid, strerror(errno));

	// child
	if (pid == 0)
	{

		// this should crash
		// (void)strlen(s);
		printf("%d\n", pid);
	}
	printf("%d\n", pid);
	int status;
	waitpid(pid, &status, 0);

	// TEST_ASSERT_GREATER_OR_EQUAL_INT32_MESSAGE(1, WIFSIGNALED(status), "child did not exit with a signal");
	// int exit_sig = WTERMSIG(status) + 128;
	printf("exit sig %d\n", exit_sig);

}
