#include "hsh.h"

/**
 * execute_cmd - executes command
 * @argv: arguments
 */
void execute_cmd(char **argv)
{
	pid_t pid;
	char *path;

	path = find_path(argv[0]);
	if (!path)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execve(path, argv, environ);
		perror("execve");
		exit(1);
	}
	else
		wait(NULL);

	free(path);
}

