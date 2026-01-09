#include "hsh.h"
#include <stdio.h>
#include <signal.h>

/**
 * handle_sigint - handle Ctrl+C
 * @sig: signal number
 */
void handle_sigint(int sig)
{
	(void)sig;
	printf("\n($) ");
	fflush(stdout);
}
