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

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execute");
		}
		exit(EXIT_FAILURE);
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
