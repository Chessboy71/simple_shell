#include "shell.h"

/**
 * _getpath - Get the full path of a cmd
 * @cmd: The cmd
 * freearr - frees the array given
 * @arr:
 * Return: 1 upon succes, 0 if no
 */

char *_getpath(char *cmd)
{
	char *pth, *dir, *fullcmd;
	int i;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
			{
				return (_strdup(cmd));
			}
			return (NULL);
		}
	}
	pth = _getenv("PATH");
	if (!pth)
		return (NULL);
	dir = strtok(pth, ":");
	while (dir)
	{
		fullcmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (fullcmd)
		{
			_strcpy(fullcmd, dir);
			_strcat(fullcmd, "/");
			_strcat(fullcmd, cmd);
			if (stat(fullcmd, &st) == 0)
			{
				free(pth);
				return (fullcmd);
			}
			free(fullcmd), fullcmd = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(pth);
	return (NULL);
}

