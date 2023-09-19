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
#define NUM_BUILTIN_COMMANDS  3

int _putchar(char c);
char **parse_arguments(char *input_command);
int contains_args(const char *command_line);
void execute_command_args(char *command_line);

char *construct_command_path(const char *command, const char *directory);
char *find_command_in_path(const char *command, const char *path);

void free_token_array(char **tokens);
char **tokenize_string(char *input_string, ssize_t input_length);
int _strlen(char *strn);
void _strcopy(char *dest, char *sourc);
char *_strdup(char *src);
int _strcomp(const char *str1, const char *str2);
void environ_builtin(void);
void exit_shell(char **command_token, char *user_input);
void deallocate_memory(char **memory_buffer);
int execute_built(char **command_args, char *user_input);
#endif
