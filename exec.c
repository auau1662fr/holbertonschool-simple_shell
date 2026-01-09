#include "hsh.h"

/**
 * execute_cmd - executes a command
 * @argv: array of arguments
 *
 * Return: 1 on failure, 0 on success
 */
int execute_cmd(char **argv)
{
	pid_t pid;
	char *path;
	int status;

	path = find_path(argv[0]);
	if (!path || access(path, X_OK) != 0)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		return (1);
	}

	pid = fork();
	if (pid == -1)
		return (1);

	if (pid == 0)
	{
		if (execve(path, argv, environ) == -1)
			exit(1);
	}
	else
	{
		wait(&status);
	}

	return (0);
}
