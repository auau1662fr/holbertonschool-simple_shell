#include "hsh.h"

/**
 * main - simple shell main loop
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **argv;

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

		argv = parse_line(line);
		if (!argv || !argv[0])
		{
			free(argv);
			continue;
		}

		if (handle_builtin(argv))
		{
			free(argv);
			continue;
		}

		execute_cmd(argv);
		free(argv);
	}
}
