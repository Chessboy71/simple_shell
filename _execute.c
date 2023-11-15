#include "shell.h"

/**
 * _execute - executes the line
 *
 * @args: the tokenised line
 * @argv : the name of the shell
 *
 * Return: 1 upon succes, 0 if no
 */

int _execute(char **args, char **argv)
{
	pid_t frk;
	int status;

	frk = fork();
	if (frk == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(argv[0]);
			freearr(args);
			exit(0);
		}
	}
	else
	{
		waitpid(frk, &status, 0);
		freearr(args);
	}
	return (WEXITSTATUS(status));
}
