#include "hsh.h"

/**
 * handle_sigint - Handles Ctrl+C (SIGINT)
 * @sig: Signal number
 */
void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n($) ", 5);
}

