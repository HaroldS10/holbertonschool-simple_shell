#include "shell.h"
int main(int ac __attribute__((unused)), char** av)
{
    int status = 0;
	char *buffer = NULL;
	size_t bufsize = 500;
	ssize_t nread;
	char **args = NULL;


	while (1)
	{

		if (isatty(STDIN_FILENO))

		buffer = malloc(500);
        write(STDOUT_FILENO, "($)", 3);

		nread = getline(&buffer, &bufsize, stdin);
		if (_strcmp(buffer, "exit\n") == 0)
			break;

		if (*buffer == '\0' || *buffer == '\n')
			continue;

		args = parse_line(buffer, av[0]);

		if(args)
			status = execute(args);
		else
		    status = 32512;

	}
	if(nread)
	{
		/**
		   do nothing*/
	}
	free(buffer);
	buffer = NULL;
	exit(WEXITSTATUS(status));
}
