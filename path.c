#include "hsh.h"

/**
 * find_path - finds command in PATH
 * @cmd: command name
 *
 * Return: full path or NULL
 */
char *find_path(char *cmd)
{
	char *path, *dir, *full;
	struct stat st;

	if (strchr(cmd, '/'))
	{
		if (stat(cmd, &st) == 0 && access(cmd, X_OK) == 0)
			return (strdup(cmd));
		return (NULL);
	}

	path = getenv("PATH");
	if (!path)
		return (NULL);

	dir = strtok(strdup(path), ":");
	while (dir)
	{
		full = malloc(strlen(dir) + strlen(cmd) + 2);
		sprintf(full, "%s/%s", dir, cmd);

		if (stat(full, &st) == 0 && access(full, X_OK) == 0)
			return (full);

		free(full);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}
