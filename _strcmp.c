#include "shell.h"

/**
 * _strcmp -  compares two strings for equality
 * @s1: first string to check
 * @s2: second input string
 * Return: 0 if equal
 */
int _strcmp(char *s1, char *s2)
{
	int i, j;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		j = s1[i] - s2[i];
		if (j != 0)
			break;
		i++;
	}
	return (j);
}
