#include "shell.h"

/**
 * execute - function that executes a given command
 * @args: array of arguments passed with the command
 * Return: exit status
 */
int execute(char **args)
{
	pid_t pid;
	int status = 0;

	if (_strcmp(args[0], "env") == 0)
	{
		builtin_env();
		return (0);
	}

	pid = fork();

	if (pid < 0)
	{
		/**
		 *Error forking
		 */
		perror("fork");
	}

	/**
	 *if pid = 0, this is the child proccess
	 */
	if (pid == 0)
	{
		/**
		 *Child process
		 */
		execve(args[0], args, environ);
	}
	else
	{
		/**
		 *Parent process
		 */
		wait(&status);
	}
	return (status);
}
