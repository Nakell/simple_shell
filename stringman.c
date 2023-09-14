#include "myshell.h"

/**
 * _strcopy - function that copies one string to another
 * @dest: the destination string
 * @sourc: the source string to be copied from
 * Return: The destination string
 */
char _strcopy(char *dest, char *sourc)
{
	int index;

	for (index = 0; index <= _strlen(sourc); index++)
	{
		dest[index] = sourc[index];
	}
	return(dest);
}
