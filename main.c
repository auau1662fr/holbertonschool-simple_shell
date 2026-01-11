#include "hsh.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_command - reads a line from stdin
 *
 * Return: pointer to line, or NULL on EOF
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}

/**
 * process_command - handles execution flow
 * @args: tokenized command
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
 * main - simple shell entry point
 *
 * Return: 0
 */
int main(void)
{
	char *line;
	char **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");

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
