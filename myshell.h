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
#include <ctype.h>
#include <signal.h>


#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
#define NUM_BUILTIN_COMMANDS  3

int _putchar(char c);
void execute_command(char *command, char **args);
void shell(void);
char *find_command_in_path(char *command, const char *path);
char *construct_command_path(const char *command, const char *directory);
int execute_built(char **command_args);
void custom_flush(void);
int _strlen(const char *strn);
char *_strdup(const char *src);
char *_strcopy(char *dest, const char *sourc);
void handle_command(char *command, char **args);
int _strcomp(const char *str1, const char *str2);


char **tokenize_string(char *input_string, ssize_t input_length);
void environ_builtin(void);
void exit_shell(void);
char **itoken(char *istring, ssize_t Bread);
void freeitoken(char **ctokens);
#endif /* MYSHELL_H */
