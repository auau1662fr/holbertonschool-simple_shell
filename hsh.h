#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;

/* main */
char **parse_line(char *line);

/* exec */
int execute_cmd(char **argv);

/* path */
char *find_path(char *cmd);

/* builtins */
int handle_builtin(char **argv);
int builtin_exit(char **argv);
int builtin_env(char **argv);

/* signals */
void handle_sigint(int sig);

#endif
