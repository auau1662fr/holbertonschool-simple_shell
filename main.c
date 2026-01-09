#include "hsh.h"

/**
 * main - Entry point of the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;

	(void)argc;

	signal(SIGINT, handle_sigint);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		args = parse_line(line);
		if (!args || !args[0])
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
