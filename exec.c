#include "hsh.h"

int execute_cmd(char **argv)
{
	pid_t pid;
	char *path;

	path = find_path(argv[0]);
	if (!path)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		execve(path, argv, environ);
		perror("execve");
		exit(1);
	}
	else if (pid > 0)
		wait(NULL);

	return (0);
}

