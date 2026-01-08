#include "hsh.h"

/**
 * handle_builtin - Executes built-in commands if they exist
 * @argv: Array of arguments
 *
 * Return: 1 if handled, 0 otherwise
 */
int handle_builtin(char **argv)
{
	if (strcmp(argv[0], "exit") == 0)
	{
		builtin_exit(argv);
		return (1);
	}
	if (strcmp(argv[0], "env") == 0)
	{
		builtin_env(argv);
		return (1);
	}
	return (0);
}

/**
 * builtin_exit - Handles the exit command
 * @argv: Array of arguments
 */
void builtin_exit(char **argv)
{
	(void)argv;
	exit(0);
}

/**
 * builtin_env - Prints environment variables
 * @argv: Array of arguments
 */
void builtin_env(char **argv)
{
	int i;

	(void)argv;
	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}

