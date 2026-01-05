#include "hsh.h"

/**
 * builtin_exit - exits the shell
 * @argv: arguments array
 *
 * Return: 1 to indicate shell should exit
 */
int builtin_exit(char **argv)
{
	(void)argv;
	return (1);
}

/**
 * handle_builtin - checks and executes builtins
 * @argv: arguments array
 *
 * Return: 1 if shell should exit, 0 otherwise
 */
int handle_builtin(char **argv)
{
	if (strcmp(argv[0], "exit") == 0)
		return (builtin_exit(argv));

	return (0);
}

