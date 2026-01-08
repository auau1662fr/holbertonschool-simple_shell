#include "hsh.h"

/**
 * execute_cmd - Executes a command with arguments
 * @argv: Array of arguments
 */
void execute_cmd(char **argv)
{
	pid_t pid;
	int status;
	char *cmd_path;

	cmd_path = find_path(argv[0]);
	if (!cmd_path)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", "./hsh", argv[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, argv, environ) == -1)
		{
			perror("execve");
			free(cmd_path);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
		perror("fork");

	free(cmd_path);
}

