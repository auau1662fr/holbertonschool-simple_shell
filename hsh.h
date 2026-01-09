#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;

/* Main */
char *read_command(void);
char **parse_line(char *line);
void process_command(char **args);

/* Builtins */
int handle_builtin(char **args);
int builtin_exit(char **args);
void builtin_env(char **args);

/* Execution */
void execute_cmd(char **args);

/* Path */
char *find_path(char *cmd);

/* Signals */
void handle_sigint(int sig);

#endif /* HSH_H */
