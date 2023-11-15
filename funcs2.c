#include "shell.h"
/**
 * is_positive_num - checks if a given string is positive
 * @s: string
 * Return: if the cmd is found in the list returns 1
 * otherwise, it retuns 0
 */
int is_positive_num(char *s)
{
	int i;

	if (!s)
		return (0);
	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}
/**
 * _atoi - comversion of strings
 * @s: the string given
 * Return: num
 */
int _atoi(char *s)
{
	int i, num = 0;

	for (i = 0; s[i]; i++)
	{
		num *= 10;
		num += (s[i] - '0');
	}
	return (num);
}
