#include "shell.h"

/**
 * prompt - prints a command prompt and waits for user input
 *
 * Return: a buffer containing the user's input
 */
char *prompt(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t chars_read = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	chars_read = getline(&buffer, &bufsize, stdin);

	if (chars_read == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(buffer);
		buffer = NULL;
	}
	else
	{
		/**
		   Remove newline character from input */
		buffer[chars_read - 1] = '\0';
	}

	return buffer;
}
