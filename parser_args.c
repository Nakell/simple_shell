#include "myshell.h"

/**
 * parse_arguments - tokenize a command string into arguments
 * @input_command: The command string to parse
 * Return: An arry of strings containing the parsed argumments
 */
char** parse_arguments(char *input_command)
{
	char **args = NULL;
	int args_count = 0;
	char *token = strtok(input_command, " ");

	while (token != NULL)
	{
		args = realloc(args, (args_count + 2) * sizeof(char *));
		if (args == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		args[args_count] = token;
		args_count++;
		token = strtok(NULL, " ");
	}
	args[args_count] = NULL;
	return args;
}
