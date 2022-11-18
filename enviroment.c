#include "shell.h"
/**
 * environment - prints the environ
 * Return: always 0
 */
int environment(void)
{
	int i;

	i = 0;
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], string_size(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
