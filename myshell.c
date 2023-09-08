#include "myshell.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

void execute_command(char *command);
void shell(void);


/**
 * shell - excutes command from user
 *
 */
void shell(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		/*  Display prompt */
		printf("$ ");
		fflush(stdout);

		/* Read command from user */
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}

		/* Remove newline character */
		command[strcspn(command, "\n")] = '\0';

		/* Execute command */
		execute_command(command);
	}
}

/**
 *  execute_command - Executes a command using the execve function.
 * @command: The command to be executed.
 */
void execute_command(char *command)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		/* Error forking */
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process*/
		execlp(command, command, NULL);

		/* Execution failed, print error message */
		fprintf(stderr, "Command '%s' not found\n", command);
		exit(EXIT_FAILURE);
	}
	else
	{

		waitpid(pid, &status, 0);
	}
}

/**
 * main - main program
 *
 *Return: return 0
 */
int main(void)
{
	shell();
	return (0);
}
