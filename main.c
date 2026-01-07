#include "hsh.h"

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
	return (0);
}
