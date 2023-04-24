#include "shell.h"

/**
 * execute - function that executes a given command
 * @args: array of arguments passed with the command
 * Return: void
 */
void execute(char **args)
{
	pid_t pid;
	int status;
	if(args[0] != NULL)
	{
	pid = fork();
	/**
	 *if pid = 0, this is the child proccess
	 */
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("execute");
		}
		exit(EXIT_FAILURE);
		if (strcmp(args[0], "env") == 0)
			builtin_env();
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		        do
			{
				wait(&status);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
}
