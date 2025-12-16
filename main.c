#include "hsh.h"

extern char **environ;

char *find_path(char *command);

/**
 * main - Entry point for simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	pid_t pid;
	int status;
	char *argv[64];
	char *cmd_path;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		if (getline(&line, &len, stdin) == -1)
			break;

		line[strcspn(line, "\n")] = '\0';

		/* Parse input */
		{
			char *token;
			int i = 0;

			token = strtok(line, " ");
			while (token != NULL)
			{
				argv[i++] = token;
				token = strtok(NULL, " ");
			}
			argv[i] = NULL;
		}

		if (argv[0] == NULL)
			continue;

		cmd_path = find_path(argv[0]);
		if (cmd_path == NULL)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
			continue;
		}

		pid = fork();
		if (pid == 0)
		{
			execve(cmd_path, argv, environ);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			wait(&status);
			free(cmd_path);
		}
		else
		{
			perror("fork");
			free(cmd_path);
		}
	}

	free(line);
	return (0);
}
