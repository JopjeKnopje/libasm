#include "libasm.h"
#include "unity.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void test_cmp_basic()
{
    const char *s1 = "test123";
    const char *s2 = "tast123";

    int expected = strcmp(s1, s2);
    int actual = ft_strcmp(s1, s2);

    TEST_ASSERT_EQUAL_INT32_MESSAGE(expected, actual, "output values don't match");
}

void test_cmp_uneven()
{
    const char *s1 = "t9st";
    const char *s2 = "tast123";

    int expected = strcmp(s1, s2);
    int actual = ft_strcmp(s1, s2);
    TEST_ASSERT_EQUAL_INT32_MESSAGE(expected, actual, "output values don't match");
}

void test_cmp_null_should_crash()
{
    const char *s1 = NULL;
    const char *s2 = "tast123";

    const pid_t pid = fork();
    TEST_ASSERT_NOT_EQUAL_INT32_MESSAGE(-1, pid, strerror(errno));
    // child proc
    if (pid == 0)
    {
        // this should crash
        int x = ft_strcmp(s1, s2);
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
