#include "hsh.h"

/**
 * main - simple shell
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;

	(void)ac;
	signal(SIGINT, handle_sigint);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(0);
		}

		args = parse_line(line);
		if (!args || !args[0])
		{
			free(args);
			continue;
		}

		if (!handle_builtin(args))
			execute_cmd(args, av[0]);

		free(args);
	}
}
