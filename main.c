#include "hsh.h"

/**
 * print_prompt - Affiche le prompt si en mode interactif
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);
}

/**
 * read_command - Lit une ligne de stdin et la retourne
 * Return: pointeur vers la ligne lue (doit être free après usage)
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
		exit(0);
	}

	return (line);
}

/**
 * process_command - Parse et exécute une commande
 * @line: ligne de commande à traiter
 */
void process_command(char *line)
{
	char **argv;

	argv = parse_line(line);
	free(line);

	if (!argv || !argv[0])
	{
		free(argv);
		return;
	}

	if (handle_builtin(argv))
	{
		free(argv);
		return;
	}

	execute_cmd(argv);
	free(argv);
}

/**
 * main - Shell principal
 * @argc: nombre d'arguments
 * @argv: arguments
 * Return: 0 en succès
 */
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	signal(SIGINT, handle_sigint);

	while (1)
	{
		char *line;

		print_prompt();
		line = read_command();
		process_command(line);
	}

	return (0);
}

/**
 * parse_line - Parse une ligne en tokens séparés par espaces
 * @line: ligne à parser
 * Return: tableau de chaînes (doit free après usage)
 */
char **parse_line(char *line)
{
	char **tokens = NULL;
	char *token;
	int i = 0, size = 10;

	tokens = malloc(sizeof(char *) * size);
	if (!tokens)
		return (NULL);

	token = strtok(line, " \t\n");
	while (token)
	{
		tokens[i++] = strdup(token);
		if (i >= size)
		{
			size += 10;
			tokens = realloc(tokens, sizeof(char *) * size);
		}
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;
	return (tokens);
}

