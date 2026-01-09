#include "hsh.h"

/**
 * handle_sigint - handles Ctrl+C
 * @sig: signal number
 */
void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n($) ", 5);
}
