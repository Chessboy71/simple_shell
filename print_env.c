#include "shell.h"
/**
 * print_env - prints the evironment variables
 *
 * @cmd: command.
 * @s: status
 * Return: nothing.
 */
void print_env(char **cmd, int *s)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearr(cmd);
	(*s) = 0;
}
