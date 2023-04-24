#include "shell.h"

/**
 * create_argv - creates a new array of strings for the execve syscall
 * @path: path to the executable file
 * @args: command-line arguments
 * Return: Pointer to the newly created array of strings
 */
char **create_argv(char *path, char **args)
{
	int arg_count = 0;
	char **argv = NULL;
	int i = 0;


	while (args[arg_count] != NULL)
		arg_count++;

	argv = malloc(sizeof(char *) * (arg_count + 2));
	if (!argv)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}


	argv[0] = path;
	for (i = 0; i < arg_count; i++)
	{
		argv[i + 1] = args[i];
	}

	argv[arg_count + 1] = NULL;

	return argv;
}
