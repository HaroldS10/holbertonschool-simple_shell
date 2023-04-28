#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

/**
 *libraries
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

/**
 *functions
*/
char *prompt(void);
char **parse_line(char *line, char *exec_name);
int execute(char **args);
char *find_path(char *file);
void builtin_env(void);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
#endif
