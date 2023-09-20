#include "myshell.h"


void execute_command(char *command);
void shell(void);

/**
 * shell - excutes command from user
 *
 */
void shell(void)
{
	char *command = NULL;
	char *command_path;
	size_t command_size = 0;
	ssize_t read_status;



	while (1)
	{
		/*  Display prompt */
		printf("$ ");

		/* Read command from user */
		read_status = getline(&command, &command_size, stdin);
		if (read_status == -1)
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
			free(command_path);
		}
			else
			{
				printf("Command not found: %s\n", command);
			}
			fflush(stdin);
	}
	free(command);
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

	if (pid == -1)
	{
		/* Error forking */
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process*/
		parse_arg(command, args);
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
