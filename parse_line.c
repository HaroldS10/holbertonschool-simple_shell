#include "shell.h"
/**
 *parse_line - function that splits a string into tokens
 *@line: line of input from user
 *Return: array of tokens
 */
char **parse_line(char *line)
{
	int bufsize = 64, position = 0, token_count = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;
	struct stat st;
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

		while (tokens[token_count] != NULL)
	{
			token_count++;
		tokens[token_count + 1] = NULL;
	}
		filestatus = stat(tokens[0],&st);

		if(getenv("PATH") != NULL)
			auxpath = find_path(tokens[0]);

		if(auxpath != NULL && tokens[0][0]!='.'&& strcmp(tokens[0],"env") != 0)
		{
			tokens[0] = auxpath;
		}
		if (auxpath != NULL)
			free(auxpath);

		if(filestatus == 0 || strcmp(tokens[0],"exit") == 0 || strcmp(tokens[0],"env") == 0)
			return (0);

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

		token = strtok(NULL, " \t\r\n\a");

	}
return (tokens);
}
