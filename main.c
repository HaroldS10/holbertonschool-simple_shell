#include "shell.h"

/**
 *main - entry point for the shell program
 *Return: 0 on success
 */

int main(void)
{
	char *buffer = malloc(500);
	size_t bufsize = 0;
	ssize_t nread;
	char **args = NULL;

	while (1)
	{
		buffer = prompt();
		nread = getline(&buffer, &bufsize, stdin);
		if (nread == -1)
		{
			if (feof(stdin))
			{
				break;
			}
			else
			{
				perror("readline");
				exit(EXIT_FAILURE);
			}
		}

		if (*buffer == '\0')
			continue;

		args = parse_line(buffer);

		execute(args);
		free(args);
	}

	free(buffer);
	return (0);

}
