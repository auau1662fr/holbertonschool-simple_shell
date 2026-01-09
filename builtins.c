#include "hsh.h"

/**
 * handle_builtin - check and execute builtin
 * @args: arguments
 *
 * Return: 1 if builtin executed, 0 otherwise
 */
int handle_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
		return (builtin_exit(args));
	if (strcmp(args[0], "env") == 0)
	{
		builtin_env(args);
		return (1);
	}
	return (0);
}

/**
 * builtin_exit - exit the shell
 * @args: arguments (optional exit code)
 *
 * Return: always 1 to indicate handled
 */
int builtin_exit(char **args)
{
	int code = 0;

	if (args[1])
		code = atoi(args[1]);
	exit(code);
}

/**
 * builtin_env - print environment variables
 * @args: arguments (unused)
 */
void builtin_env(char **args)
{
	int i;

	(void)args;
	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}
