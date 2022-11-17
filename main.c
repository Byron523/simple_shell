#include "simple_shell.h"

/**
* main - shell entry point
* @ac: argument count
* @av: argument vector
* Return: always 0
*/
int main(int ac __attribute__((unused)), char **av)
{
	int fd_isatty;

	fd_isatty = isatty(STDIN_FILENO);
	if (fd_isatty == 0)
	{
		piper(av);
	}
	else
	{
		while_loop(av);
	}
	return (0);
}