#include "shell.h"

/**
 *main - entry point for the shell program
 *Return: 0 on success
 */

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 500;
	ssize_t nread;
	char **args = NULL;
/*	int i;*/

	buffer = malloc(500);
	while (1)
	{
/*		i = 0;*/
		if (isatty(STDIN_FILENO))

			write(STDOUT_FILENO, "($)", 3);


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

		if (*buffer == '\0' || *buffer == '\n')
			continue;

		args = parse_line(buffer);
/**
 *		while(args[i] != NULL)
 *		{
 *			printf("%s\n",args[i]);
 *			i++;
 *		}
 */

		if(args)
		{
			execute(args);
			free(args);
		}

	}

	free(buffer);
	return (0);

}
