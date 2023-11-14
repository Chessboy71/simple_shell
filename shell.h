#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

extern char **environ;

char *read_line();
char **tokenise(char *ln);
int _execute(char **args, char **argv);

#endif
