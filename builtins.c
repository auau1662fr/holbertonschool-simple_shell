#include "hsh.h"

/**
 * handle_builtin - Gère les commandes internes du shell
 * @argv: Tableau des arguments
 *
 * Return: 1 si builtin exécuté, 0 sinon
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
 * builtin_exit - Quitte le shell
 * @argv: Tableau des arguments
 *
 * Return: Rien
 */

int builtin_exit(char **argv)
{
	(void)argv;
	exit(0);
}

/**
 * builtin_env - Affiche l'environnement
 * @argv: Tableau des arguments
 *
 * Return: Rien
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

