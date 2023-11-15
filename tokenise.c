#include "shell.h"

/**
 * tokenise - takes the whole line and tansforms it into tokens
 *
 * @ln : the line inserted
 *
 * Return: the tokenised line
 */

char **tokenise(char *ln)
{
	int i = 0, j = 0;
	char **cmd = NULL;
	char *tmp = NULL, *tkn = NULL;

	tmp = strdup(ln);
	tkn = strtok(tmp, " \n\t");
	if (!tkn)
	{
		free(ln);
		free(tmp);
		return (NULL);
	}
	while (tkn)
	{
		tkn = strtok(NULL, " \n\t");
		i++;
	}
	free(tmp), tmp = NULL;

	cmd = malloc(sizeof(char *) * (i + 1));
	if (!cmd)
	{
		free(ln), ln = NULL;
		return (NULL);
	}
	tkn = strtok(ln, " \n\t");
	while (tkn)
	{
		cmd[j] = strdup(tkn);
		tkn = strtok(NULL, " \n\t");
		j++;
	}
	cmd[j] = NULL;
	free(ln), ln = NULL;
	return (cmd);
}
