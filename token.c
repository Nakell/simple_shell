#include "myshell.h"

/**
 * parse_arg - Parses the command and tokenizes it into arguments.
 * @command: The command to be parsed.
 * @args: The array to store the arguments.
 */
void parse_arg(char *command, char **args)
{
	int args_count = 0;
	char *start = command;
	char *end = start;
	size_t token_length = end - start;

	while (*command != '\0' && args_count < MAX_ARGUMENTS)
	{
		/* Skip leading whitespace */
		while (*start == ' ')
		{
			start++;
		}

		if (*start == '\0')
		{
			break;
		}

		while (*end != '\0' && *end != ' ')
		{
			end++;
		}

		args[args_count] = (char *)malloc(token_length + 1);
		if (args[args_count] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		_strcopy(args[args_count], start);

		args_count++;
		start = end + 1;
	}

	args[args_count] = NULL;
}
