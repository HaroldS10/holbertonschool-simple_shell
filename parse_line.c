#include "shell.h"

/**
 *parse_line - function that splits a string into tokens
 *@line: line of input from user
 *Return: array of tokens
 */

char **parse_line(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize*(sizeof(char*)));
	char *token = NULL;
	struct stat st;
	int filestatus = 0;
	char *auxpath = NULL;

/**
	 *conditional checking whether the tokens pointer is null or not.
	 */

	if (!tokens)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, " \t\r\n\a");
	}

	/**
	 *check if tokens[0] eixst in PATH
	 */

	filestatus = stat(tokens[0], &st);
	if (getenv("PATH") != NULL && filestatus == -1)
	{
		auxpath = find_path(tokens[0]);
		if (auxpath != NULL)
		{
			tokens[0] = auxpath;
		}
		else
		{
			perror("test");
			return (NULL);
		}
	}
	tokens[position] = NULL;


	return (tokens);
}
