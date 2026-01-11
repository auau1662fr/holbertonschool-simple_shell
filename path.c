#include "hsh.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

/**
 * build_path - builds full executable path
 * @dir: directory from PATH
 * @cmd: command name
 *
 * Return: full path string
 */
static char *build_path(char *dir, char *cmd)
{
	char *path;
	size_t len;

	len = strlen(dir) + strlen(cmd) + 2;
	path = malloc(len);
	if (!path)
		return (NULL);

	sprintf(path, "%s/%s", dir, cmd);
	return (path);
}

/**
 * find_path - finds command in PATH
 * @cmd: command
 *
 * Return: full path or NULL
 */
char *find_path(char *cmd)
{
	char *env, *copy, *dir, *path;

	if (strchr(cmd, '/'))
		return (access(cmd, X_OK) == 0 ? strdup(cmd) : NULL);

	env = getenv("PATH");
	if (!env)
		return (NULL);

	copy = strdup(env);
	dir = strtok(copy, ":");

	while (dir)
	{
		path = build_path(dir, cmd);
		if (path && access(path, X_OK) == 0)
		{
			free(copy);
			return (path);
		}
		free(path);
		dir = strtok(NULL, ":");
	}

	free(copy);
	return (NULL);
}
