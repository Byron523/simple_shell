#include "shell.h"

/**
 * str_cpy - cpies a string to another variable
 * @s1: desc
 * @s2: src
 * Return: ponter 2 a copy of the new string
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
