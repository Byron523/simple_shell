#include "shell.h"

/**
 * splits - splits a string using tokeinzation
 * @buf: input string
 * @size: sizeof chars to be split
 * Return: a pointer to the splitted string
 */
char **splits(char *buf, int size)
{
	char *delim = " =:'\n''\t'";
	int i;
	char **token, *token2 = NULL;

	token = malloc(sizeof(char *) * size);
	if (token == NULL)
		return (NULL);

	token2 = strtok(buf, delim);
	i = 0;
	while (token2 != NULL)
	{
		token[i] = str_dup(token2);
		if (token[i] == NULL)
		{
			_free(2, token);
			return (NULL);
		}
		token2 = strtok(NULL, delim);
		i++;
	}
	token[i] = NULL;
	return (token);
}
