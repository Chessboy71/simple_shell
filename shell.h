#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>

extern char **environ;

char *read_line();
char **tokenise(char *ln);
int _execute(char **args, char **argv, int i);
void freearr(char **arr);

char *_getpath(char *cmd);
char *_getenv(char *varia);
char *_itoa(int n);
void reverse_string(char *str, int len);

/* string function */
int _strlen(char *s);
char *_strdup(const char *str);
char *_strcat(char *dest, char *str);
char *_strcpy(char *dest, char *str);
void printerr(char *nm, char *cmd, int i);
#endif
