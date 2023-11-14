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
	int status;

	(void)ac;

	while (1)
	{
		line = read_line();
		if (line == NULL)
			return (0);
		printf("%s", line);
		cmd = tokenise(line);
		if (!cmd)
			continue;
		status = _execute(cmd, argv);
	}
	return (WEXITSTATUS(status));
}
