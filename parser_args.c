#include "myshell.h"

/**
 * parse_arg - Parses the command and tokenizes it into arguments.
 * @command: The command to be parsed.
 * @args: The array to store the arguments.
 */
void parse_arg(char *command, char **args)
{
	char *token;
	int args_count = 0;

	token = strtok(command, " ");
	while (token != NULL && args_count < MAX_ARGUMENTS)
	{
		args[args_count] = token;
		args_count++;
		token = strtok(NULL, " ");
	}

	args[args_count] = NULL;
}
