#include "simple_shell.h"

/**
 * while_loop - loop that accepts user input
 * @av: argument vector/input from the cmd line
 * Return: exit/failure code
 */

int while_loop(char **av __attribute__((unused)))
{
	size_t size;
	char *buf = NULL, *cmd = NULL;
	char **cmd_input = NULL;
	int (*builtin)() = NULL;
	char **args = NULL;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		getline(&buf, &size, stdin);
		is_valid(buf, 0, cmd_input, args);

		if (buf[0] == 10 || buf[0] == 9)
			continue;

		cmd_input = construct(buf);
		if (cmd_input == NULL)
			continue;

		builtin = builtin_func(*cmd_input);
		if (builtin)
		{
			if (builtin == left)
				free_path(cmd_input, args, buf, NULL);
			builtin();

			free_path(cmd_input, NULL, NULL, NULL);
			continue;
		}

		args = get_path();
		if (args == NULL)
			return (-1);

		cmd = insert(cmd_input, args);
		if (cmd == NULL)
			write(STDOUT_FILENO, "command NOT found\n", 18);
		else
			execute(cmd, cmd_input);

		_free(1, buf), buf = NULL;
		_free(2, cmd_input), cmd_input = NULL;
		_free(2, args), args = NULL;
	}
	return (0);
}