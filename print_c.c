#include "main.h"
/**
 * printf _char - To print character
 * @val: Is the argument
 * Return: 1
 */
int printf_char(va_list val)
{
	char str;

	str = va_arg(val, int);
	_putchar(str);
	return (1);
}
	
