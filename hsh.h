#ifndef HSH_H
#define HSH_H

/* ========= STANDARD LIBRARIES ========= */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

extern char **environ;

int main(void);

void shell_loop(void);

char **parse_line(char *line);

char *find_path(char *command);

void execute_command(char **argv, char *prog_name);

int handle_builtin(char **argv);
int builtin_exit(char **argv);
int builtin_env(void);
int builtin_cd(char **argv);

void handle_sigint(int sig);

void free_argv(char **argv);

#endif
