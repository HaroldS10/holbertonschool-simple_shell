#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

/**
 libraries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 prototypes */

char **parse_line(char *line);
void execute(char **args);
char **create_argv(char *path, char **args);

#endif
