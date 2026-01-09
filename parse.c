#include "hsh.h"

/**
 * parse_line - splits a line into arguments
 * @line: input line
 *
 * Return: array of arguments
 */
char **parse_line(char *line)
{
	char **args = malloc(sizeof(char *) * 64);
	char *token;
	int i = 0;

	if (!args)
		return (NULL);

	token = strtok(line, " \t\n");
	while (token)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;

	return (args);
}
