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
		pid = fork();
	/**
         *if pid = 0, this is the child proccess
         */
	if (pid == 0)
	{
		if (strcmp(args[0], "env") == 0)
			builtin_env();
		/**
		    Child process */
		if (execve(args[0], args, environ) == -1)
		{
		    perror("execute");
			exit(EXIT_FAILURE);
		}

		else if (pid < 0)
		{
			/**
			   Error forking */
			perror("fork");
		}
		else
		{
			/**
			   Parent process */
                do
		{
		wait(&status);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
}
