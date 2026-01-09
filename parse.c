#include "hsh.h"

/**
 * parse_line - split line into arguments
 * @line: input line
 *
 * Return: array of arguments
 */
char **parse_line(char *line)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 64);
	if (!tokens)
		return (NULL);

	token = strtok(line, " \t\n");
	while (token)
	{
		tokens[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;

	return (tokens);
}
