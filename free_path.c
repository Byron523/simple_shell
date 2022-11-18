#include "shell.h"

/**
 * free_path - frees memory of a path
 * @pt1: a double pointer
 * @pt2: a second pointer
 * @pnt: third pointer
 * @pnt1: anohter oner
 * Return: non
 */
void free_path(char **pt1, char **pt2, char *pnt, char *pnt1)
{
	if (pt1 != NULL)
	{
		_free(2, pt1);
		pt1 = NULL;
	}

	if (pt2 != NULL)
	{
		_free(2, pt2);
		pt2 = NULL;
	}

	if (pnt != NULL)
	{
		free(pnt);
		pnt = NULL;
	}

	if (pnt1 != NULL)
	{
		free(pnt1);
		pnt1 = NULL;
	}
}
