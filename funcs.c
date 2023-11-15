#include "shell.h"

/**
 * freearr - frees the array given
 *
 * @arr:
 *
 * Return: 1 upon succes, 0 if no
 */

void freearr(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; arr[i] = NULL)
		free(arr[i]), arr[i] = NULL;
	free(arr), arr = NULL;
}

