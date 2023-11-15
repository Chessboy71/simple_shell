#include "shell.h"

/**
 * freearr - frees the array given
 *
 * @arr:
 *
 * Return: 1 upon succes, 0 if no
 */

void freearr(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]), arr[i] = NULL;
	free(arr), arr = NULL;
}

/**
 *_itoa - frees the array given
 *
 * @n: the number
 *
 * Return: 1 upon succes, 0 if no
 */

char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	reverse_string(buffer, i);
	return (strdup(buffer));
}
/**
 * reverse_string - reverses a string
 * @str : string
 * @len : the length
 */

void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
/**
 * printerr - print the error
 * @nm : name of the shell
 * @cmd : the command
 * @i : the number
 *
 */

void printerr(char *nm, char *cmd, int i)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(i);

	write(STDERR_FILENO, nm, _strlen(nm));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));

	free(index);
}
