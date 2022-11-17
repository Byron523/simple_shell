#include "simple_shell.h"

/**
 * execute - execute the given cmd
 * @s1: the cmd given
 * @arg: cmd arguments
 * Return: 0 or error number
*/
int execute(char *s1, char **arg)
{
	int status;
	pid_t pid;
	int error;

	error = 0;
	pid = fork();
	if (!pid)
	{
		if (execve(s1, arg, environ) == -1)
		{
			_free(1, s1);
			s1 = NULL;
			error = errno;
			exit(error);
		}
		else
		{
			_free(1, s1);
			s1 = NULL;
			exit(error);
		}
	}
	else
		wait(&status);

	_free(1, s1);
	s1 = NULL;
	return (error);
}