#include "hsh.h"

/**
 * handle_sigint - Gère le signal CTRL+C
 * @sig: Signal reçu
 *
 * Return: Rien
 */

void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
}

