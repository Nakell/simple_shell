#include "myshell.h"

/**
 * token_string - function to tokenize string into a single token
 * @input_string: the input string to be tokenized
 * @token: a poitner to store the single token
 */
void token_string(char *input_string, char **token)
{
	*token = _strdup(input_string);
	if (*token == NULL)
	{
		perror("_strdup");
		exit(EXIT_FAILURE);
	}
}
int mymain()
{
	char input_string[] = "ls -l /tmp";
	char *token = NULL;
	token_string(input_string, &token);
	printf("Token: %s/n", token);
	free(token);
	return (0);
}
