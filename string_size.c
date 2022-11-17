#include "simple_shell.h"

/**
 * string_size - returns the size of the string
 * @s: input string
 * Return: size of string
*/
int string_size(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}