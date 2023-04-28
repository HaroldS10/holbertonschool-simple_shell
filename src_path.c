#include "shell.h"

/**
 * find_path - Search for a file in the PATH
 * @file: String to file to search
 * Return: Path to file if found, or NULL if not found in any path
 */

char *find_path(char *file)
{
	char *path, *direction, *auxpath;
	struct stat st;
	int pathlen, filelen, filestatus, dirlen;

	pathlen = _strlen(getenv("PATH"));
	path = calloc((pathlen + 1), sizeof(*path));
	if (path == NULL)
		return (NULL);
	auxpath = path;
	_strcpy(path, getenv("PATH"));
	path = strtok(path, ":");
	filelen = _strlen(file);
	while (path)
	{
/**
   printf("Actual dir: %s\n", path);*/
        pathlen = _strlen(path);
		direction = calloc((pathlen + filelen + 2), sizeof(*direction));
		if (direction == NULL)
			return (NULL);
		_strcpy(direction, path);
		dirlen = _strlen(direction);
		if (direction[dirlen - 1] != '/')
			direction[dirlen] = '/';
		direction = _strcat(direction, file);
/**
   printf("Got direction: %s\n", direction);*/
		filestatus = stat(direction, &st);
		if (filestatus == 0)
		{
			free(auxpath);
			return (direction);
		}
		free(direction);
		path = strtok(NULL, ":");

	}
	free(auxpath);
	return (NULL);
}
