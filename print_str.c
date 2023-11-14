#include "main.h"

/**
 * _strlen - Returns the string length
 * @str: Pointer to String
 * Return: Length of the string
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
		;
	return (i);
}

/**
 * _strlenc - Returns the length of
 * constant character pointer string
 * @str: Pointer to character
 * Return: Length of the string
 */
int _strlenc(const char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
		;
	return (i);
}

