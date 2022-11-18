#include "shell.h"

/**
 * construct - looks for pipes in the commands
 * @buf: input command(s)
 * Return: the commands
 */
char **construct(char *buf)
{
	int i;
	char **cmd_input = NULL;

	i = cmd_count(buf);
	cmd_input = splits(buf, i);
	if (cmd_input == NULL)
	{
		_free(2, cmd_input);
		cmd_input = NULL;
	}
	return (cmd_input);
}
