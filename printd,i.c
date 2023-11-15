#include "main.h"

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
