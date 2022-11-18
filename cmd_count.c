#include "shell.h"

/**
 * cmd_count - counts the number of commands
 * @buf: input commands from the user
 * Return: number of arguments
 */
int cmd_count(char *buf)
{
	int i = 0, j, k = 0;
	char *delim = " =:'\''\t'";

	while (buf[i] != '\0')
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (buf[i] == delim[j])
			{
				k++;
				break;
			}
		}
		i++;
	}
	return (k + 1);
}
