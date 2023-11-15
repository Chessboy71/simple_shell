#include "shell.h"
/**
 * exit_shell - exits the shell
 * @cmd: command
 * @arg: arguments
 * @s: status
 * @i: index
 * Return: 0 on success.
 */
void exit_shell(char **cmd, char **arg, int *s, int i)
{
	int exit_val = *s;
	char *ind;
	char msg[] = ": exit: illegal number: ";

	if (cmd[1])
	{
		if (is_positive_num(cmd[1]))
		{
			exit_val = _atoi(cmd[1]);
			freearr(cmd);
		}
		else
		{
			ind = _itoa(i);
			write(STDERR_FILENO, arg[0], _strlen(arg[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, ind, _strlen(ind));
			write(STDERR_FILENO, msg, _strlen(msg));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(ind), ind = NULL;
			freearr(cmd);
			*s = 2;
			return;
		}
	}
	freearr(cmd);
	exit(exit_val);
}
