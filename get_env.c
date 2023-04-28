#include "shell.h"

/**
 * env_builtin - prints the environment
 */

void builtin_env(void)
{
	int i;

	if (environ)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
}
