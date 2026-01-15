#include <unistd.h>

const char *text_var = "text123";

int main()
{
	write(1, text_var, 8);
}
