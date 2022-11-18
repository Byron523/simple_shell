#include "shell.h"

/**
 * path_locater - locates the path of the envrion
 * Return: pointer to path
 */
char *path_locater()
{
	char *s;
	int i;

	s = NULL;
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strcmp(environ[i], "PATH") == 0)
		{
			s = malloc(sizeof(char *) * string_size(environ[i]));
			if (s == NULL)
			{
				_free(1, s);
				exit(-1);
			}
			str_cpy(s, environ[i]);
			break;
		}
	}
	return (s);
}
