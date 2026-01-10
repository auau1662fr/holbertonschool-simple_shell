#include "hsh.h"

/**
 * read_command - Reads a line from standard input
 *
 * Return: Pointer to the line read, or NULL on EOF
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}

/**
 * process_command - Processes and executes a command
 * @args: Array of arguments
 *
 * Return: void
 */
void process_command(char **args)
{
	if (!args || !args[0])
		return;

	if (handle_builtin(args))
		return;

	execute_cmd(args);
}

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *line;
	char **args;

	signal(SIGINT, handle_sigint);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		line = read_command();
		if (!line)
			break;

		args = parse_line(line);
		process_command(args);

		free(args);
		free(line);

		if (!isatty(STDIN_FILENO))
			break;
	}

	return (0);
}

