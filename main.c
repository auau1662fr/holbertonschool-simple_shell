#include "hsh.h"

/**
 * read_command - read input from stdin
 *
 * Return: input line
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * process_command - handle command execution
 * @args: arguments
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
 * main - simple shell
 *
 * Return: 0
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
	}
	return (0);
}
