#include "hsh.h"

/**
 * shell_loop - Main shell loop
 * @argv: Argument vector
 *
 * Return: Always 0
 */
int shell_loop(char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t bytes_read;
	char **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		bytes_read = getline(&line, &len, stdin);
		if (bytes_read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		args = parse_line(line);
		if (args == NULL || args[0] == NULL)
		{
			free(args);
			continue;
		}

		if (handle_builtin(args) == 0)
			execute_cmd(args, argv[0]);

		free(args);
	}

	free(line);
	return (0);
}

/**
 * main - Entry point of the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	(void)argc;

	signal(SIGINT, handle_sigint);

	shell_loop(argv);

	return (0);
}
