#include "myshell.h"

/**
 * tokenize_string - function to tokenize a string based on delimiters
 * @input_string: the input string to be tokenized
 * @input_length: the number of bytes read from the input string
 * Return - an array of token pointers
 */
char **tokenize_string(char *input_string, ssize_t input_length)
{
	char **tokens = NULL;
	char *delimiters = "\t\n\0";
	char *token_index = 0, j;
	int token_length;

	tokkens = malloc(sizeof(char *) * (input_length + 1));
	if (tokens == NULL)
		return(NULL);
	token = strok(input_string, delimeters);

	while (token != NULL)
	{
		token_length = _strlen(token);
		tokens[token_index] = malloc(sizeof(char) * (token_length + 1));
		if (tokens[token_index] == NULL)
		{
			for (j = 0; j < token_index; j++)
			{
				free(tokens[k]);
			}
			free(tokens);
			return(NULL);
		}
		_strcopy(tokens[token_index], token);
		token = strtok(NULL, delimiters);
	}
	tokens[tokens_index] = NULL;
	return(tokens);
}

