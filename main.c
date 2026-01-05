#include "hsh.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *argv[64];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		if (getline(&line, &len, stdin) == -1)
			break;

		line[strcspn(line, "\n")] = '\0';

		/* Parsing */
		{
			char *token;
			int i = 0;

			token = strtok(line, " ");
			while (token)
			{
				argv[i++] = token;
				token = strtok(NULL, " ");
			}
			argv[i] = NULL;
		}

		if (argv[0] == NULL)
			continue;

		execute_cmd(argv);
	}

	free(line);
	return (0);
}

