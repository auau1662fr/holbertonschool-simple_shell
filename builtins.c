#include "hsh.h"

/**
 * handle_builtin - checks builtins
 * @argv: arguments
 *
 * Return: 1 if builtin, 0 otherwise
 */
int handle_builtin(char **argv)
{
	if (strcmp(argv[0], "exit") == 0)
		return (builtin_exit(argv));
	if (strcmp(argv[0], "env") == 0)
		return (builtin_env(argv));
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

