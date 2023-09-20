#include "myshell.h"

/**
 * _strcopy - function that copies one string to another
 * @dest: the destination string
 * @sourc: the source string to be copied from
 */
void _strcopy(char *dest, char *sourc)
{
	int index;

	for (index = 0; index <= _strlen(sourc); index++)
	{
		dest[index] = sourc[index];
	}
	dest[index] = '\0';
}

/**
 * _strcomp - function that compares two strings
 * @str1: the first string to compare
 * @str2: the second string to compare
 * Return: 0
 */
int _strcomp(const char *str1, const char *str2)
{
	int index = 0;

	while (str1[index] != '\0' || str2[index] != '\0')
	{
		if (str1[index] != str2[index])
		{
			return (str1[index] - str2[index]);
		}
		index++;
	}
	return (0);

}

/**
 * _strdup - duplicates a string
 * @src: the string to be duplicated
 * Return: a pointer to the duplicated string
 */
char *_strdup(const char *src)
{
	char *duplic;
	int i, length;

	if (src == NULL)
		return (NULL);
	length = _strlen(src);
	duplic = malloc(sizeof(char) * (length + 1));
	if (!duplic)
		return (NULL);
	for (i = 0; src[i] != '\0'; i++)
		duplic[i] = src[i];
	duplic[i] = '\0';
	return (duplic);
}
