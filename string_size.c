#include "shell.h"

/**
 * string_size -  returns size of a string
 * @s: input string
 * Return: size of a string
 */
int string_size(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
