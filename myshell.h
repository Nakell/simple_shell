#ifndef MYSHELL_H
#define MYSHELL_H

extern char **environ;
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <stddef.h>
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10


int _putchar(char c);
char** parse_arguments(char *input_command);
int contains_args(const char *command_line);
void execute_command_args(char *command_line);
#endif
