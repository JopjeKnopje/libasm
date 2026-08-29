#include "libasm.h"
#include "string.h"
#include "unity.h"
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void test_valid_string(void)
{
    const char *s = "123";

    const int expected = strlen(s);
    const int actual = ft_strlen(s);

    TEST_ASSERT_EQUAL_INT32_MESSAGE(expected, actual, "output values don't match");
}

void test_null_should_crash(void)
{
    const char *s = NULL;

    const pid_t pid = fork();
    TEST_ASSERT_NOT_EQUAL_INT32_MESSAGE(-1, pid, strerror(errno));

    // child proc
    if (pid == 0)
    {
        // this should crash
        int x = ft_strlen(s);
        // we need this cast otherwise the compiler will optimize our function call away,
        (void)x;
        // exit as a fallback
        exit(1);
    }
    int status;
    const pid_t code = waitpid(pid, &status, 0);
    TEST_ASSERT_NOT_EQUAL_INT32_MESSAGE(-1, code, "error waitpid returned %d [%s]\n", code,
                                        strerror(errno));

    TEST_ASSERT_TRUE_MESSAGE(WIFSIGNALED(status), "strlen process did not exit with signal");

    const int exit_sig = WTERMSIG(status);
    TEST_ASSERT_TRUE_MESSAGE(exit_sig == SIGSEGV, "strlen exited with signal [%s] expected [%s]\n",
                             strsignal(exit_sig), strsignal(SIGSEGV));
}
