#include "hsh.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * execute_cmd - executes a command
 * @args: arguments
 *
 * Return: void
 */
void execute_cmd(char **args)
{
	pid_t pid;
	char *path;

	path = find_path(args[0]);
	if (!path)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execve(path, args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);

	free(path);
}

