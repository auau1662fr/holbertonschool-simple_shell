#include "hsh.h"

/**
 * execute_cmd - executes a command
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on failure
 */
int execute_cmd(char **argv)
{
	pid_t pid;
	char *path;
	int status;

	path = find_path(argv[0]);
	if (!path)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		return (1);
	}

	pid = fork();
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
