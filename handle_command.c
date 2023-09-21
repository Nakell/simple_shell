#include "myshell.h"

/**
 * handle_command - handles args
 * @command: The command to execute.
 *@args: argments to be passed
 */

void handle_command(char *command, char **args)
{
	if (command == NULL)
	{
		fprintf(stderr, "Invalid command\n");
		return;
	}
	execute_command(command, args);
}
