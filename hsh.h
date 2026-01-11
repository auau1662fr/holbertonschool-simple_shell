#ifndef HSH_H
#define HSH_H

#include <stddef.h>

/* main */
char *read_command(void);
void process_command(char **args);

/* parse */
char **parse_line(char *line);

/* exec */
void execute_cmd(char **args);

/* path */
char *find_path(char *cmd);

/* builtins */
int handle_builtin(char **args);
void builtin_exit(char **args);
void builtin_env(void);

/* signals */
void handle_sigint(int sig);

extern char **environ;

#endif

