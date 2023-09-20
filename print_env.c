#include "myshell.h"

/**
 * environ_builtin - function impelements the "env" builtin command
 */
void environ_builtin(void)
{
	int env_index = 0;
	char **env_var = environ;

	while (env_var[env_index] != NULL)
	{
		write(STDOUT_FILENO, (const void *) env_var[env_index],
				_strlen(env_var[env_index]));
		write(STDOUT_FILENO, "\n", 1);
		env_index++;
	}
}
