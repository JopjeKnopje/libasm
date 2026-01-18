#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

const char *text_var = "text123";

int main()
{
    ssize_t x = ft_write(STDOUT_FILENO, text_var, strlen(text_var));
    (void)x;
    return 0;
}
