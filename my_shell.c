#include "myshell.h"


void execute_command(char *command, char **args);
void shell(void);

/**
 * shell - excutes command from user
 *
 */
void shell(void)
{
	char *args[MAX_ARGUMENTS + 1];
	char *command = NULL;
	char *command_path;
	ssize_t read;
	size_t len = 0;


	while (1)
	{
		/*  Display prompt */
		printf("$ ");
		fflush(stdout);

		/* Read command from user */
		read = getline(&command, &len, stdin);
		if (read == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}


		/* Remove newline character */
		if (read > 0 && command[read - 1] == '\n')
		{
			command[read - 1] = '\0';
		}

		parse_arg(command, args);


		/* sets path for command */
		command_path = find_command_in_path(command, getenv("PATH"));
		if (command_path != NULL)
		{
			/*executes the command */
			execute_command(command_path, args);
			free(command_path);
		}
			else
			{
				printf("Command not found: %s\n", command);
			}
			free(command);
	}
	free(command);
}

/**
 *  execute_command - Executes a command using the execve function.
 * @command: The command to be executed.
 * @args: The array of arguments for the command
*/
void execute_command(char *command, char **args)
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
		execve(command, args, environ);


		/* Execution failed, print error message */
		fprintf(stderr, "Command '%s' not found\n", args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{

		waitpid(pid, &status, 0);
	}
}
/**
 * main - main program
 * Return: 0
 */
int main(void)
{
	shell();
	return (0);
}
