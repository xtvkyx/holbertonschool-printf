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
