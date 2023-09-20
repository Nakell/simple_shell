#include "myshell.h"

/**
 * handle_command - handles args
 *@args: argments to be passed
 */

void handle_command(char **args)
{
	execute_command(args[0], args);
}
