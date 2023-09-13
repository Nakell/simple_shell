#include "myshell.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

void execute_command(char *command);
void shell(void);
char *find_command_in_path(const char *command, const char *path);

/**
 * shell - excutes command from user
 *
 */
void shell(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *command_path;

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

		/* sets path for command */
		command_path = find_command_in_path(command, getenv("PATH"));
		if (command_path != NULL)
		{
			/*executes the command */
			execute_command(command_path);
		}

			else
			{
				printf("Command not found: %s\n", command);
			}
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
	char *args[MAX_ARGUMENTS + 1];
	char *token;

	int args_count = 0;

	if (pid == -1)
	{
		/* Error forking */
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process*/
		/* tokenize */
		token = strtok(command, " ");
		while (token != NULL && args_count < MAX_ARGUMENTS)
		{
			args[args_count] = token;
			args_count++;
			token = strtok(NULL, " ");
		}
		args[args_count] = NULL;

		execvp(args[0], args);

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
 * Return: 0
 */
int main(void)
{
	shell();
	return (0);
}
