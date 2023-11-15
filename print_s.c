#include "main.h"
#include <stdarg.h>
/**
 * printf_string - Prints a string to the standard output
 * @val: The string to be printed
 * Return: The length of the printed string
 */
int printf_string(va_list val)
{
	char *str;
	int i;
	int length;

	str = va_arg(val, char *);
	if (str == NULL)
	{
	str = "(null)";
	length = _strlen(str);
	for (i = 0; i < length; i++)
		_putchar(str[i]);
	return (length);
	}
	else
	{
	length = _strlen(str);
	for (i = 0; i < length; i++)
		_putchar(str[i]);
	return (length);
	}
}

