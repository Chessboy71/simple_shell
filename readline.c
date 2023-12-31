#include "shell.h"

/**
 * read_line - reads the current line
 *
 * Return: the line
 */

char *read_line()
{
	char *ln = NULL;
	size_t n = 0;
	ssize_t line;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	line = getline(&ln, &n, stdin);
	if (line < 0)
	{
		free(ln);
		return (NULL);
	}
	return (ln);
}
