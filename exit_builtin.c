#include "myshell.h"
/**
 * exit_shell - funciton exit shell
 * @command: pointer to the input
 */
void exit_shell(char *command)
{
	free(command);
	exit(EXIT_SUCCESS);
}
