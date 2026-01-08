#include "hsh.h"

/**
 * find_path - Returns the full path of a command using PATH
 * @cmd: Command name
 *
 * Return: Full path string (malloc'd) or NULL if not found
 */
char *find_path(char *cmd)
{
	char *path_env;
	char *path_dup;
	char *dir;
	char *full_path;
	int len;

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);

	path_dup = strdup(path_env);
	if (!path_dup)
		return (NULL);

	dir = strtok(path_dup, ":");
	while (dir)
	{
		len = snprintf(NULL, 0, "%s/%s", dir, cmd) + 1;
		full_path = malloc(len);
		if (!full_path)
		{
			free(path_dup);
			return (NULL);
		}
		snprintf(full_path, len, "%s/%s", dir, cmd);

		if (access(full_path, X_OK) == 0)
		{
			free(path_dup);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_dup);
	return (NULL);
}

