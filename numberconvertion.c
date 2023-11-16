#include "main.h"

/**
 * printable - Checks whether a characters is printable
 * @c: Character to be checked
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * add_hexa_code - Add hexadecimal ASCII code to the buffer.
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int add_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* Hexa is always +2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Checks if a character is a digit.
 * @c: The character to be checked.
 *
 * Return: 1 if c is a digit, else 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_num_size - converts a number to the specified size
 * @n: Number to be type casted.
 * @size: Indicator of the type to be cast.
 *
 * Return: Casted n value
 */
long int convert_num_size(long int n, int size)
{
	if (size == 2)
		return (n);
	else if (size == 1)
		return ((short)n);
	else
		return ((int)n);
}

/**
 * typecast_unsgndint_size - typecasts unsigned int to the specified size
 * @n: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of n
 */
long int typecast_unsgndint_size(unsigned long int n, int size)
{
	if (size == 2)
		return (n);
	else if (size == 1)
		return ((unsigned short)n);
	else
		return ((unsigned int)n);
}

