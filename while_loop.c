#include "shell.h"

/**
 * while_loop - entry point to the terminal
 * @buf: input command
 * Return: exit or failure
 */
int while_loop(char **buf __attribute__((unused)))
{
	char *buffer = NULL, *cmd = NULL;
	char **cmd_input = NULL;
	int (*builtin)() = NULL;
	char **args = NULL;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		buffer = get_line();
		is_valid(buffer, 0, cmd_input, args);

		if (buffer[0] == 10 || buffer[0] == 9)
			continue;

		cmd_input = construct(buffer);
		if (cmd_input == NULL)
			continue;

		builtin = builtin_func(*cmd_input);
		if (builtin)
		{
			if (builtin == left)
				free_path(cmd_input, args, buffer, NULL);
			builtin();

			free_path(cmd_input, NULL, NULL, NULL);
			continue;
		}
		args = get_path();
		if (args == NULL)
			return (-1);

		cmd = insert(cmd_input, args);
		if (cmd == NULL)
			write(STDOUT_FILENO, "command not found\n", 18);
		else
			execute(cmd, cmd_input);

		_free(1, buf), buf = NULL;
		_free(2, cmd_input), cmd_input = NULL;
		_free(2, args), args = NULL;
	}
	return (0);
}
