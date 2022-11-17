#include "simple_shell.h"

/**
 * piper - executes command lines entered by pipe
 * @av: program name
 * Return: 0
*/
int piper(char **av __attribute__((unused)))
{
	size_t size;
	int i;
	char *buf = NULL, *cmd = NULL;
	char **cmd_input = NULL;
	int (*builtin)() = NULL;
	char **args = NULL;

	i = 0;
	while ((i = getline(&buf, &size, stdin)) > 0)
	{
		is_valid(buf, i, cmd_input, args);
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
			write(STDOUT_FILENO, "command not found\n", 18);
		else
			execute(cmd, cmd_input);

		_free(1, buf), buf = NULL;
		_free(2, cmd_input), cmd_input = NULL;
		_free(2, args), args = NULL;
	}
	_free(1, buf), buf = NULL;
	return (0);
}
