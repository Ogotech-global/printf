#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: Format string containing specifiers.
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	int character_print = 0;
	va_list argument_list;

	if (format == NULL)
	return (-1);

	va_start(argument_list, format);

	while (*format)
	{
	if (*format != '%')
	{
		write(1, format, 1);
		 character_print++;
	}
	else
	{
		format++;
		if (*format == '\0')
		{
			break;
		}
		else if (*format == '%')
		{
		write(1, format, 1);
		character_print++;
		}
		else if (*format == 'c')
		{
		int c = va_arg(argument_list, int);
		write(1, &c, 1);
		character_print++;
		}
		else if (*format == 's')
		{
		char *str = va_arg(argument_list, char *);
		int str_len = 0;

		while (str[str_len] != '\0')
			str_len++;
		write(1, str, str_len);
		character_print += str_len;
		}
		else if (*format == 'd' || *format == 'i')
		{
		int num = va_arg(argument_list, int);
		character_print += print_number(num);
		}
		else
		{
		write(1, "%", 1);
		write(1, format, 1);
		character_print += 2;
		}
	}
	format++;
	}
	va_end(argument_list);
	return (character_print);
}

/**
 * print_number - Prints an integer.
 * @n: The integer to be printed.
 * Return: Number of digits printed.
 */
int print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
	write(1, "-", 1);
	n = -n;
	count++;
	}

	if (n / 10)
	count += print_number(n / 10);

	write(1, &((char)(n % 10 + '0')), 1);

	return (count + 1);
}
