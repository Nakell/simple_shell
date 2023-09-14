#include "myshell.h"

/**
 * free_token_array - function to free memory allocated for an array of tokens
 * @tokens: the array of token pointers to be freed
 */
void free_token_array(char **tokens)
{
	int index;
	if (tokens == NULL)
		return;
	for (index = 0; tokens[index] != NULL; index++)
	{
		free(tokens[index]);
	}
	free(tokens);
}
