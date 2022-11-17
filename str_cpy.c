#include "simple_shell.h"

/**
 * str_cpy - copies string to another variable
 * @s1: 1st string to be copied desc
 * @s2: 2ndto be copied from
 * Return: a copy of a new string
*/
char *str_cpy(char *s1, char *s2)
{
	int i, j;

	i = 0;
	while (s2[i] != '\0')
		i++;

	for (j = 0; j <= i; j++)
	{
		s1[j] = s2[j];
	}
	return (s1);
}