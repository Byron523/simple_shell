#include "simple_shell.h"

/**
 * is_valid - checks the validity of a line
 * @buf: input buffer
 * @i: size of buf
 * @arg: arguments
 * @args: env args
 * Return: 0
*/
void is_valid(char *buf, int i, char **arg, char **args)
{
	if (i == EOF)
	{
		printf("Reached EOF\n");
		write(STDOUT_FILENO, "\n", 1);
		if (buf != NULL)
		{
			_free(1, buf);
			buf = NULL;
		}

		if (arg != NULL)
		{
			_free(2, arg);
			arg = NULL;
		}

		if (args != NULL)
		{
			_free(2, args);
			args = NULL;
		}
		exit(0);
	}
}