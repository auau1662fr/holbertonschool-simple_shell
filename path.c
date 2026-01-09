#include "hsh.h"

/**
 * find_path - find the command in PATH
 * @cmd: command name
 *
 * Return: full path if found, NULL otherwise
 */
char *find_path(char *cmd)
{
	char *path_env, *path_copy, *dir, *full_path;
	size_t len;

	if (strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (strdup(cmd));
		return (NULL);
	}

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	dir = strtok(path_copy, ":");

	while (dir)
	{
		len = strlen(dir) + strlen(cmd) + 2;
		full_path = malloc(len);
		if (!full_path)
			return (NULL);

		sprintf(full_path, "%s/%s", dir, cmd);
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
