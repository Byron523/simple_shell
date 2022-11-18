#include "shell.h"

/**
 * str_dup - duplictes a string
 * @buf: input string
 * Return: a pointer to the duplicate string
 */
char *str_dup(char *buf)
{
	char *cpy;
	int i, size;

	size = string_size(buf);
	cpy = malloc(sizeof(char) * (size = 1));
	if (cpy == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		cpy[i] = buf[i];
	cpy[i] = '\0';
		return (cpy);
}
