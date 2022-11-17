#include "simple_shell.h"

/**
 * environment - prints the environment
 * Return: always 0
*/
int environment(void)
{
	int i, j;

	i = 0;
	while (environ[i] != NULL)
	{
		for (j = 0; environ[j] != NULL; j++)
			;

		write(STDOUT_FILENO, environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}