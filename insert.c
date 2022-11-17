#include "simple_shell.h"

/**
 * equate - just like comp  function below
 * @s: string one
 * @s2: second string
 * Return: int
*/
int equate(char *s, char *s2)
{
	while (*s && *s2)
	{
		if (*s != *s2)
			return (0);
		s++;
		s2++;
	}
	return (*s2 == '\0');
}

/**
 * comp - compares two strings at a given pos
 * @s: string one
 * @s2: second string
 * Return: pointer to first occurence
*/
char *comp(char *s, char *s2)
{
	while (*s != '\0')
	{
		if ((*s == *s2) && equate(s, s2))
			return (s);
		s++;
	}
	return (NULL);
}

/**
 * insert - inserts cmd into appropriate pos
 * @s1: the cmd
 * @path: the position or path
 * Return: path or a given cmd
*/
char *insert(char **s1, char **path)
{
	char *cwd;
	int i, j, k, l;
	char *tmp, *dpath;
	struct stat verify;

	cwd = getcwd(NULL, 0);
	i = 0;
	j = 0;
	dpath = NULL, tmp = NULL;
	if (comp(s1[0], "/") || comp(s1[0], "."))
	{
		_free(1, cwd);
		cwd = NULL;

		for (k = 0; s1[k] != '\0'; k++)
			;

		tmp = malloc(sizeof(char *) * k);
		str_cpy(tmp, s1[0]);
		return (tmp);
	}
	else
	{
		while (path[i] != NULL)
		{
			chdir(path[i]);
			if (stat(s1[0], &verify) == 0)
			{
				for (l = 0; path[l] != NULL; l++)
					;

				for (k = 0; s1[k] != NULL; k++)
					;

				j = l + 1 + k;
				tmp = malloc(sizeof(char *) * j);
				str_cpy(tmp, path[i]);
				concat(tmp, "/"), concat(tmp, path[i]);
				break;
			}
			i++;
		}
	}

	chdir(cwd);
	if (tmp == NULL)
	{
		_free(1, cwd), cwd = NULL;
		_free(1, tmp), tmp = NULL;
		return (dpath);
	}
	dpath = tmp, _free(1, cwd), cwd = NULL;
	return (dpath);
}

/**
 * concat - a function to concat strings
 * @s1: string 1, desc
 * @s2: string 2, src
 * Return: s1
*/
char *concat(char *s1, char *s2)
{
	int a, b;

	for (a = 0; s1[a] != '\0'; a++)
		;

	for (b = 0; s2[b] != '\0'; b++)
	{
		s1[a + b] = s2[b];
	}
	s1[a + b] = '\0';

	return (s1);
}