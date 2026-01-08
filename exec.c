#include "hsh.h"

/**
 * execute_cmd - Exécute une commande
 * @argv: Tableau des arguments
 *
 * Return: 0 en cas de succès, sinon 1
 */

int execute_cmd(char **argv)
{
	char *cmd_path;
	pid_t pid;
	int status;

	/* Cherche la commande dans le PATH */
	cmd_path = find_path(argv[0]);
	if (!cmd_path)
	{
/* Commande introuvable, affiche erreur comme ./hsh: 1: cmd: not found */
	fprintf(stderr, "%s: 1: %s: not found\n", "./hsh", argv[0]);
	return (1);
	}

/* Fork uniquement si la commande existe */
	pid = fork();
	if (pid == -1)
	{
	perror("fork");
	free(cmd_path);
	return (1);
	}

	if (pid == 0) /* Processus enfant */
	{
	if (execve(cmd_path, argv, environ) == -1)
		{
		perror("execve");
		free(cmd_path);
		exit(EXIT_FAILURE);
		}
	}
	else /* Parent attend */
	{
	waitpid(pid, &status, 0);
	}

	free(cmd_path);
	return (0);
}

