#include "simple_shell.h"

/**
 * construct - looks for pipes in a command
 * @buf: input command
 * Return: the commands
*/
char **construct(char *buf)
{
	int i;
	char **cmd_input = NULL;

	i = 0;
	i = cmd_count(buf);
	cmd_input = splits(buf, i);
	if (cmd_input == NULL)
	{
		_free(2, cmd_input);
		cmd_input = NULL;
	}

	return (cmd_input);
}