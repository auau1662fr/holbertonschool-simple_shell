#include "hsh.h"

/**
 * find_path - Finds full path of a command
 * @command: command name
 *
 * Return: full path or NULL
 */
char *find_path(char *command)
{
	char *path_env, *path_copy, *dir, *full_path;
	size_t len;

	if (!command)
		return (NULL);

	if (strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		return (NULL);
	}

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	dir = strtok(path_copy, ":");

	while (dir)
	{
		len = strlen(dir) + strlen(command) + 2;
		full_path = malloc(len);
		sprintf(full_path, "%s/%s", dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

