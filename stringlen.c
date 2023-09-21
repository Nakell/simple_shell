#include "myshell.h"

/**
 * _strlen - function to calculate the length of a string
 * @strn: The input string
 * Return: The length of the string
 */
int _strlen(const char *strn)
{
	int length = 0;

	for (length = 0; strn[length] != '\0'; length++)
	{}
	return (length);
}

