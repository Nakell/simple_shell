#include "myshell.h"

/**
 * execute_built - this fucntions executes builtins commands
 * @command_args: tokenized command arguments
 * Return:1 if a builtin command is executed, 0 otherwise
 */
int execute_built(char **command_args)
{
	char *builtin_command[NUM_BUILTIN_COMMANDS] = {"env", "exit"};
	int command_index;

	for (command_index = 0; command_index < NUM_BUILTIN_COMMANDS; command_index++)
	{
		if (_strcomp(*command_args, builtin_command[command_index]) == 0)
		{
			if (command_index == 0)
			{
				environ_builtin();
			}
			else if (command_index == 1)
			{
				printf("exit command detected.\n");
				exit_shell();
			}
			return (1);
		}
	}
	return (0);
}
