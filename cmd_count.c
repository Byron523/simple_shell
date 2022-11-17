#include "simple_shell.h"

/**
 * cmd_count - counts number of cmd line arguments
 * @buf: the input buffer from getline
 * Return: number of arguments
 */
int cmd_count(char *buf)
{
	char *delim = " =:'\n''\t'";
	int i, j, k;

	i = 0, k = 0;
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