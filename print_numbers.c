#include "main.h"
#include <stdarg.h>

/**
 * print_number - prints an integer recursively
 * @n: the integer to print
 * Return: number of characters printed
 */
int print_number(long int n)
{
	int count = 0;
	unsigned long int num;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_number(num / 10);

	count += _putchar((num % 10) + '0');

	return (count);
}

/**
 * _printint - prints an integer argument
 * @ap: va_list containing the integer
 * Return: number of characters printed
 */
int _printint(va_list ap)
{
	long int n = va_arg(ap, int);

	return (print_number(n));
}

/**
 * print_unsigned_base - prints an unsigned int in a given base
 * @n: the unsigned int number
 * @base: base to convert (e.g. 10, 8, 16)
 * @uppercase: flag to use uppercase letters for hex
 * Return: number of characters printed
 */
int print_unsigned_base(unsigned int n, int base, int uppercase)
{
	char digits[] = "0123456789abcdef";
	char digits_upper[] = "0123456789ABCDEF";
	char buffer[32];
	int i = 0, count = 0;

	if (n == 0)
		return (_putchar('0'));

	while (n > 0)
	{
		if (uppercase)
			buffer[i++] = digits_upper[n % base];
		else
			buffer[i++] = digits[n % base];
		n /= base;
	}

	while (i--)
		count += _putchar(buffer[i]);

	return (count);
}

/**
 * _printunsigned - handles %u
 */
int _printunsigned(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	return (print_unsigned_base(n, 10, 0));
}

/**
 * _printoctal - handles %o
 */
int _printoctal(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	return (print_unsigned_base(n, 8, 0));
}
