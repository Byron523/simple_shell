#include "simple_shell.h"

/**
 * path_locater - locates the path var from environ
 * Return: pointer to path
*/
char *path_locater()
{
	char *s;
	int i, j;

	s = NULL;
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strcmp(environ[i], "PATH") == 0)
		{
			for (j = 0; environ[j] != NULL; j++)
				;

			s = malloc(sizeof(char *) * j);
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