#include "main.h"
/**
 * printf_char - Prints a character to the standard output
 * @val: The character to be printed
 * Return: 1
 */
int printf_char(va_list val)
{
	_putchar(va_arg(val, int));
	return (1);
}

