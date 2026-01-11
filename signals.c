#include "hsh.h"
#include <signal.h>
#include <unistd.h>

/**
 * handle_sigint - handles Ctrl+C
 * @sig: signal number
 *
 * Return: void
 */
void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n($) ", 5);
}

