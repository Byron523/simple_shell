#include "simple_shell.h"

/**
 * _free - frees memory allocated
 * @i: int value
 * Return: none
*/
void _free(int i, ...)
{
	int j;
	char **val1 = NULL;
	char *val2 = NULL;
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