#include "hsh.h"

/**
 * execute_cmd - executes a command
 * @args: command arguments
 * @av: program name
 */
void execute_cmd(char **args, char *av)
{
	pid_t pid;
	char *cmd_path;

	cmd_path = find_path(args[0]);
	if (!cmd_path)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", av, args[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execve(cmd_path, args, environ);
		perror(av);
		exit(1);
	}
	else
		wait(NULL);

	free(cmd_path);
}
