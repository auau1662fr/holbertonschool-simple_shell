#include "hsh.h"

/**
 * parse_line - Parse la ligne de commande en tokens
 * @line: La ligne de commande à parser
 *
 * Return: Tableau de tokens (char **)
 */

char **parse_line(char *line)
{
	char **argv;
	char *token;
	int i = 0;

	argv = malloc(sizeof(char *) * 64);
	if (!argv)
		return (NULL);

	token = strtok(line, " \t\n");
	while (token)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;
	return (argv);
}

/**
 * main - Entry point of the shell
 * @argc: Number of arguments
 * @argv: Arguments array
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;

	(void)argc;
	(void)argv;

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

		if (handle_builtin(args))
		{
			free(args);
			continue;
		}

		execute_cmd(args);
		free(args);
	}
	return (0);
}
