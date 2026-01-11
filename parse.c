#include "hsh.h"
#include <stdlib.h>
#include <string.h>

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n"

/**
 * parse_line - splits a line into tokens
 * @line: input line
 *
 * Return: array of tokens
 */
char **parse_line(char *line)
{
	int bufsize = TOK_BUFSIZE, i = 0;
	char **tokens;
	char *token;

	tokens = malloc(sizeof(char *) * bufsize);
	if (!tokens)
		return (NULL);

	token = strtok(line, TOK_DELIM);
	while (token)
	{
		tokens[i++] = token;
		token = strtok(NULL, TOK_DELIM);
	}

	tokens[i] = NULL;
	return (tokens);
}

