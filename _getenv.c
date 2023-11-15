#include "shell.h"

/**
 * _getenv - gets the enviroment variable
 *
 * @varia: ssd
 *
 * Return: 1 upon succes, 0 if no
 */

char *_getenv(char *varia)
{
	char *tmp, *key, *env, *val;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = strdup(environ[i]);
		key = strtok(tmp, "=");
		if (strcmp(key, varia) == 0)
		{
			val = strtok(NULL, "\n");
			env = strdup(val);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
