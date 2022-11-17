#include "simple_shell.h"

/**
 * str_dup - duplicates a string
 * @buf: input string
 * Return: duplicate string
*/
char *str_dup(char *buf)
{
	char *cpy;
	int i, size;

	for (size = 0; buf[size] != '\0'; size++)
		;

	cpy = malloc(sizeof(char) * (size + 1));
	if (cpy == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		cpy[i] = buf[i];
	cpy[i] = '\0';
	return (cpy);
}