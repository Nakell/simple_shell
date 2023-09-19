#include "myshell.h"
/**
 * exit_shell - this function exits shell
 * @command_token: tokenized command
 * @user_input:input read from stdin
 * This fucntion exits the shell and deallocates memory
 *
 */
void exit_shell(char **command_token, char *user_input)
{
	int index = 0;

	while (command_token[index])
	{
		free(command_token[index]);
		index++;
	}
	free(command_token);
	free(user_input);
	exit(0);
}
