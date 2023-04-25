#include "shell.h"

/**
 *parse_line - function that splits a string into tokens
 *@line: line of input from user
 *Return: array of tokens
 */

char **parse_line(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = NULL;
	char *token = NULL;

	int filestatus;
	char *auxpath;


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

	if (strstr(tokens[0],"/") != NULL && strcmp(tokens[0],"env") != 0 && strcmp(tokens[0],"exit") != 0)
	{
			tokens[0] = auxpath;
		}

	if(getenv("PATH") != NULL)
		auxpath = find_path(tokens[0]);

	if (auxpath != NULL)
			{
				tokens[0] = auxpath;
				free(auxpath);
			}
}

return (NULL);

if (position >= bufsize)
{
	bufsize += 64;
	tokens = realloc(tokens, bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}
}

tokens[position] = NULL;
return (tokens);
}
