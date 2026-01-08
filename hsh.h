#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <stddef.h>

/* Function prototypes */
char **parse_line(char *line);
char *find_path(char *cmd);
void execute_cmd(char **argv);
int handle_builtin(char **argv);
void builtin_exit(char **argv);
void builtin_env(char **argv);
void handle_sigint(int sig);

extern char **environ;

#endif

