#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

char **parse_line(char *line);
char *find_path(char *cmd);
int handle_builtin(char **args);
void execute_cmd(char **args, char *av);
void handle_sigint(int sig);

#endif

