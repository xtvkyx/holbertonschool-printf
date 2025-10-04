#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_number - prints an integer recursively
 * @n: the integer to print
 * Return: number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		count += print_number(num / 10);

	_putchar((num % 10) + '0');
	count++;

	return (count);
}

/**
 * _printint - prints an integer argument
 * @ap: va_list containing the integer
 * Return: number of characters printed
 */
int _printint(va_list ap, flags_t flags)
{
	int n = va_arg(ap, int);
	char sign = 0;
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		sign = '-';
		num = -n;
	}
	else
	{
		num = n;
		if (flags.plus)
			sign = '+';
		else if (flags.space)
			sign = ' ';
	}

	if (sign)
		count += _putchar(sign);

	count += print_number(num);
	return (count);
}

/**
 * print_unsigned_base - prints an unsigned int in a given base
 * @n: the unsigned int number
 * @base: base to convert (10, 8, 16)
 * @uppercase: 1 for uppercase hex, 0 for lowercase
 * Return: number of characters printed
 */
int print_unsigned_base(unsigned int n, int base, int uppercase)
{
	char digits[] = "0123456789abcdef";
	char digits_upper[] = "0123456789ABCDEF";
	char buffer[32];
	int i = 0, count = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		if (uppercase)
			buffer[i++] = digits_upper[n % base];
		else
			buffer[i++] = digits[n % base];
		n /= base;
	}

	while (i--)
	{
		_putchar(buffer[i]);
		count++;
	}
	return (count);
}

/**
 * _printunsigned - prints %u
 */
int _printunsigned(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	return (print_unsigned_base(n, 10, 0));
}

/**
 * _printoctal - prints %o
 */
int _printoctal(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	return (print_unsigned_base(n, 8, 0));
}
