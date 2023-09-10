#include "myshell.h"

/**
 * execute_command_args - this function execute a command with arguments
 * @command_line: the command line to execute
 */
void execute_command_args(char *command_line)
{
	pid_t pid;
	int status;
	char *command = strtok(command_line, " ");
	char *args[MAX_ARGUMENTS];
	int args_count = 0;

	args[args_count++] = command;

	while ((args[args_count] = strtok(NULL, " ")) != NULL)
	{
		args_count++;
		if (args_count >= MAX_ARGUMENTS)
		{
			fprintf(stderr, "Too many arguments.\n");
			return;
		}
	}
	args[args_count] = NULL;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

/**
 * contains_args - function checks if a command line contains spaces
 * (indicating arguments)
 * @command_line: the commadn line to be checked
 * REturn: 1 if arguments are found, otherwise 0
 */
int contains_args(const char *command_line)
{
	while (*command_line)
	{
		if (*command_line == ' ')
		{
			return(1);
		}
		command_line++;
	}
	return(0);
}
void execute_command_args_shell(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}
		command[strcspn(command, "\n")] = '\0';

		if (contains_args(command))
		{
			execute_command_args(command);
		}
		else
		{
			printf("Command '%s' not found\n", command);
		}
	}
}
