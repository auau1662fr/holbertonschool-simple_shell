#include "hsh.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * builtin_exit - exits shell
 * @args: arguments
 *
 * Return: void
 */
void builtin_exit(char **args)
{
	(void)args;
	exit(0);
}

/**
 * builtin_env - prints environment
 *
 * Return: void
 */
void builtin_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * handle_builtin - checks builtins
 * @args: arguments
 *
 * Return: 1 if builtin, 0 otherwise
 */
int handle_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		builtin_exit(args);
		return (1);
	}
	if (strcmp(args[0], "env") == 0)
	{
		builtin_env();
		return (1);
	}
	return (0);
}
