#include "hsh.h"

/**
 * execute_cmd - execute external command
 * @args: arguments array
 */
void execute_cmd(char **args)
{
	pid_t pid;
	int status;
	char *cmd_path;

	cmd_path = find_path(args[0]);
	if (!cmd_path)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execve(cmd_path, args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("fork");
	else
		waitpid(pid, &status, 0);

	free(cmd_path);
}
