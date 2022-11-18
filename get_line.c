#include "shell.h"
/**
 * _append - append a char to a string
 * @buf: allocated bufer string
 * @pntr: to size holding the string
 * @s: input char to append
 * @i: the index pos
 * Return: 1 otherwise 0
 */
int ap_ppend(char **buf, size_t *pntr, char s, unsigned long int i)
{
	size_t c;
	char *buffer;

	if (!(buf && *buf))
		return (0);

	if (pntr == NULL)
		for (c = 0; (*buf)[c]; c++)
			continue;
	else
		c = *pntr;
	buffer = *buf;S
	while (c <= i)
	{
		c *= 2;
		buffer = realloc(buffer, c);
		if (!buf)
			return (0);
	}
	buffer[i] = s;
	*buf = buffer;
	if (pntr != NULL)
		*pntr = c;
	return (1);
}
/**
 * get_line - gets the input from stdin
 * Return: the input
 */
char *get_line()
{
	int i, c;
	size_t bufsize;
	char *buffer;

	bufsize = 1024;
	buffer = malloc(bufsize), i = 0;
	if (buffer == NULL)
	{
		perror("Error");
		exit(errno);
	}
	c = fgetc(stdin);

	while (c != EOF)
	{
		if (c == '\n')
		{
			ap_ppend(&buffer, &bufsize, '\0', i);
			break;
		}
		ap_ppend(&buffer, &bufsize, c, i);
		i++;
		c = fgetc(stdin);
	}
	if (c == EOF)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
