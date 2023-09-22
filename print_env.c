#include "myshell.h"

/**
 * environ_builtin - function impelements the "env" builtin command
 */
void environ_builtin(void)
{
	int i = 0, env_index = 0;

	while (environ[i])
	{
		env_index = _strlen(environ[i]);

		write(STDOUT_FILENO, environ[i], env_index);
		write(STDOUT_FILENO, "\n", 1);
		env_index++;
	}
}
