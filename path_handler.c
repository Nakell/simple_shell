#include "myshell.h"

/**
 * construct_command_path - Constructs the full path to a command.
 * @command: The name of the command.
 * @directory: The directory path where the command is located.
 *
 * Return: dynamically allocated str containing full path to the command.
 */
char *construct_command_path(const char *command, const char *directory)
{
	char *command_path = malloc(_strlen(directory) + strlen(command) + 2);

	if (command_path == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	sprintf(command_path, "%s/%s", directory, command);

	return (command_path);
}

/**
 * find_command_in_path - Searches for a cmd in the dir specified in the PATH.
 * @command: The name of the command to search for.
 * @path: The value of the PATH environment variable.
 *
 * Return: dynamically allocated str containing full path to cmd.
 */
char *find_command_in_path(char *command, const char *path)
{
	char *path_copy = _strdup(path);
	char *directory = strtok(path_copy, ":");
	char *command_path  = NULL;
	char *found_path = NULL;

	if (command[0] == '/')
	{
		if (access(command, X_OK) == 0)
		{
			found_path = _strdup(command);
		}
		free(path_copy);
		return (found_path);
	}

	if (path_copy == NULL)
	{
		perror("_strdup");
		exit(EXIT_FAILURE);
	}

	while (directory != NULL)
	{
		command_path = construct_command_path(command, directory);
		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (command_path);
		}
		free(command_path);
		directory = strtok(NULL, ":");
	}

	free(path_copy);

	return (found_path);
}
