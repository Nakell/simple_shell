#include "myshell.h"


/**
 * freeitoken - free memory used by tokenized strings
 * @ctokens: Array of command tokens
 */
void freeitoken(char **ctokens)
{
	int m;

	if (ctokens == NULL)
		return;
	for (m = 0; ctokens[m] != NULL; m++)
	{
		free(ctokens[m]);
	}
	free(ctokens);
}


/**
 * itoken - thes function tokenize string based on delimiters
 * @istring: input string to tokenize
 * @Bread: number of bytes read
 * Return: array of command tokens
 */
char **itoken(char *istring, ssize_t Bread)
{
	char **ctokens = NULL;
	char *delim = " \t\n\0";
	char *token = NULL;
	int m = 0, n;
	int tokenL;

	ctokens = malloc(sizeof(char *) * (Bread + 1));
	if (ctokens == NULL)
		return (NULL);
	token = strtok(istring, delim);

	while (token != NULL)
	{
		tokenL = _strlen(token);
		ctokens[m] = malloc(sizeof(char) * (tokenL + 1));
		if (ctokens[m] == NULL)
		{
			for (n = 0; n < m; n++)
			{
				free(ctokens[m]);
			}
			free(ctokens);
			return (NULL);
		}
		_strcopy(ctokens[m], token);
		token = strtok(NULL, delim);
		m++;
	}
	ctokens[m] = NULL;
	return (ctokens);
}
