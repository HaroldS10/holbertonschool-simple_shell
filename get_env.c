#include "shell.h"
/**
 * env_builtin - prints the environment
 */
void env_builtin(void)
{
	int i;

	if (environ)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
}
