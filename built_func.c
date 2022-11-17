#include "simple_shell.h"

/**
 * builtin_func - looks for built in functions
 * @s: in put cmd
 * Return: an pointer to func
*/
int (*builtin_func(char *s))()
{
	int i, j;

	b_s m_func[] = {
		{"exit", left},
		{"env", environment},
	};

	i = 0;
	j = (sizeof(m_func) / sizeof(b_s));
	if (s != NULL)
	{
		while (i < j)
		{
			if (_strcmp(m_func[i].b_n, s) == 0)
				return (m_func[i].b_f);
			i++;
		}
	}
	return (NULL);
}