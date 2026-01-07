#include "hsh.h"

int handle_builtin(char **argv)
{
	if (strcmp(argv[0], "exit") == 0)
		return (builtin_exit(argv));

	if (strcmp(argv[0], "env") == 0)
		return (builtin_env(argv));

	return (0);
}

int builtin_exit(char **argv)
{
	(void)argv;
	exit(0);
}

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

