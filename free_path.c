#include "simple_shell.h"

/**
 * free_path - frees memory
 * @ptr1: 1st pntr
 * @ptr2: 2nd pntr
 * @ptr3: 3rd pntr
 * @ptr4: 4th pntr
 * Return: nothing
*/
void free_path(char **ptr1, char **ptr2, char *ptr3, char *ptr4)
{
	if (ptr1 != NULL)
	{
		_free(2, ptr1);
		ptr1 = NULL;
	}

	if (ptr2 != NULL)
	{
		_free(2, ptr2);
		ptr2 = NULL;
	}

	if (ptr3 != NULL)
	{
		free(ptr3);
		ptr3 = NULL;
	}

	if (ptr4 != NULL)
	{
		free(ptr4);
		ptr4 = NULL;
	}
}