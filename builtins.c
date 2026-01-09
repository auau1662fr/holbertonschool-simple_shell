#include "hsh.h"

/**
 * handle_builtin - handles builtin commands
 * @args: arguments
 *
 * Return: 1 if builtin, 0 otherwise
 */
int handle_builtin(char **args)
{
	int i;

	if (strcmp(args[0], "exit") == 0)
		exit(0);

	if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		return (1);
	}
	return (0);
}

/**
 * builtin_exit - exits shell
 * @argv: arguments
 *
 * Return: 1
 */
int builtin_exit(char **argv)
{
	(void)argv;
	exit(0);
}

/**
 * builtin_env - prints environment
 * @argv: arguments
 *
 * Return: 1
 */
int builtin_env(char **argv)
{
	int i = 0;

	(void)argv;
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}

