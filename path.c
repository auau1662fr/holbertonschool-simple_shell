#include "hsh.h"

/**
 * find_path - finds command in PATH
 * @cmd: command name
 *
 * Return: full path or NULL
 */
char *find_path(char *cmd)
{
	char *path_env, *path_copy, *dir;
	static char full_path[1024];

	if (access(cmd, X_OK) == 0)
		return (cmd);

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	dir = strtok(path_copy, ":");

	while (dir)
	{
		sprintf(full_path, "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
