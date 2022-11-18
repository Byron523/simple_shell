#include "shell.h"

/**
 * _free - frees alocated memory
 * @i: number of arguments
 * Return: nothing
 */
void _free(int i, ...)
{
	int j;
	char *val2 = NULL;
	char **val1 = NULL;
	va_list args;

	va_start(args, i);
	if (i == 1)
	{
		val2 = va_arg(args, char *);
		free(val2);
	}

	j = 0;
	if (i == 2)
	{
		val1 = va_arg(args, char **);
		while (val1[j] != NULL)
		{
			free(val1[j]);
			j++;
		}
		free(val1);
	}
}
