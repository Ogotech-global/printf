#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: Format string containing specifiers.
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	int character_print = 0;
	va_list args;

	if (!format)
	return (-1);

	va_start(args, format);

	while (*format)
	{
	if (*format != '%')
		write(1, format, 1), character_print++;
	else
	{
		format++;
		if (*format == '\0')
			break;
		else if (*format == '%')
		write(1, format, 1), character_print++;
		else if (*format == 'c')
		character_print += print_char(args);
		else if (*format == 's')
		character_print += print_string(args);
		else if (*format == 'd' || *format == 'i')
		character_print += print_number(args);
		else
		write(1, "%", 1), write(1, format, 1), character_print += 2;
	}

	format++;
	}

	va_end(args);
	return (character_print);
}

/**
 * print_char - Print a character.
 * @args: Argument list.
 * Return: Number of characters printed.
 */
int print_char(va_list args)
{
	int c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Print a string.
 * @args: Argument list.
 * Return: Number of characters printed.
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (!str)
	str = "(null)";

	while (str[len] != '\0')
	len++;

	write(1, str, len);
	return (len);
}

/**
 * print_number - Print a number.
 * @args: Argument list.
 * Return: Number of characters printed.
 */
int print_number(va_list args)
{
	int num = va_arg(args, int);
	int num_digits = 0;
	int temp = num;

	while (temp != 0)
	{
	temp /= 10;
	num_digits++;
	}

	while (num_digits > 0)
	{
	int divisor = power(10, --num_digits);
	int digit = num / divisor + '0';

	write(1, &digit, 1);
	num %= divisor;
	}
	return (num_digits);
}

/**
 * power - Calculate the power of a number.
 * @base: Base value.
 * @exponent: Exponent value.
 * Return: Result of base raised to the power of exponent.
 */
int power(int base, int exponent)
{
	int result = 1;

	while (exponent > 0)
	{
	result *= base;
	exponent--;
	}
	return (result);
}

