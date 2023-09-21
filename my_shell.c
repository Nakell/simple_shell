#include "myshell.h"

void execute_command(char *command, char **args);
void shell(void);
void parse_arg(char *command, char **args);
char *find_command_in_path(char *command, const char *path);

/**
 * shell - excutes command from user
 *
 */
void shell(void)
{
	char *command = NULL;
	char *command_path;
	ssize_t read;
	size_t len = 0;
	char **tokeargs;

	while (1)
	{
		/*  Display prompt */
		if (isatty(STDIN_FILENO))
		{
			const char *shellprompt = "$ ";

			write(STDOUT_FILENO, shellprompt, _strlen(shellprompt));
			fflush(stdout);
		}

		/* Read command from user */
		read = getline(&command, &len, stdin);
		if (read  == -1)
		{
			perror("getline");
			free(command);
			exit(EXIT_FAILURE);
		}

		/* Remove newline character */
		if (read > 0 && command[read - 1] == '\n')
		{
			command[read - 1]  = '\0';
		}


		if (_strcomp(command, "exit") == 0)
		{
			free(command);
			exit_shell();
		}
		/* Parse the command and find its path */
		tokeargs = itoken(command, read);
		if (tokeargs != NULL)
		{
			command_path = find_command_in_path(tokeargs[0], getenv("PATH"));
		if (command_path != NULL)
		{
			/*executes the command */
			execute_command(command_path, tokeargs);
			free(command_path);
		}
		else
		{
			printf("Command not found: %s\n", tokeargs[0]);
		}
		freeitoken(tokeargs);
		}
		else
		{
			fprintf(stderr, "token error\n");
		}
		free(command);
	}
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
