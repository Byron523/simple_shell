#include "shell.h"

/**
 * get_path - looks for paths in diff functions
 * Return: pntr to an address to tokenized dir
 */
char **get_path()
{
	char *tmp = NULL;
	int i;
	char **env;

	tmp = path_locater();
	change_sign(tmp);
	i = cmd_count(tmp);
	env = splits(tmp, i);
	_free(1, env);
	tmp = NULL;

	return (env);
}

/**
 * change_sign - changes the sign of the path
 * @s: input string
 * Return: nothing
 */
void change_sign(char *s)
{
	char **ptr = NULL;
	int i;

	ptr = &s;
	i = 0;
	while ((*(*ptr + i)) != '=')
	{
		(*(*ptr + i)) = ':';
		i++;
	}
	(*(*ptr + i)) = ':';
}
