#include "shell.h"

/**
 * _execute - executes the line
 *
 * @args: the tokenised line
 * @argv : the name of the shell
 * @i : index
 *
 * Return: 1 upon succes, 0 if no
 */

int _execute(char **args, char **argv, int i)
{
	pid_t frk;
	int status;
	char *cmd;

	cmd = _getpath(args[0]);
	if (!cmd)
	{
		free(cmd);
		printerr(argv[0], args[0], i);
		freearr(args);
		exit(127);
	}

	frk = fork();
	if (frk == 0)
	{
		if (execve(cmd, args, environ) == -1)
		{
			free(cmd), cmd = NULL;
			freearr(args);
			exit(0);
		}
	}
	else
	{
		waitpid(frk, &status, 0);
		freearr(args);
		free(cmd);
	}
	return (WEXITSTATUS(status));
}
