#include "shell.h"

/**
 * main - the main function
 *
 * @ac: the int
 * @argv : the name of the shell
 *
 * Return: 1 upon succes, 0 if no
 */

int main(int ac, char **argv)
{
	char *line = NULL;
	char **cmd = NULL;
	int status, i = 0;

	(void)ac;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		i++;
		cmd = tokenise(line);
		if (!cmd)
			continue;
		status = _execute(cmd, argv, i);
	}
	return (WEXITSTATUS(status));
}
