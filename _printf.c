#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <limits.h>

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
 * print_normal - prints a single character from the format string
 * @format: the format string
 * @i: pointer to current index
 * Return: number of characters printed (always 1)
 */
int print_normal(const char *format, int *i)
{
	write(1, &format[*i], 1);
	(*i)++;
	return (1);
}

/**
 * handle_unknown - handles unknown format specifiers
 * @c: the unknown character
 * Return: number of characters printed
 */
int handle_unknown(char c)
{
	write(1, "%", 1);
	write(1, &c, 1);
	return (2);
}

/**
 * handle_format - handles valid format specifiers
 * @c: the format character
 * @ap: va_list of arguments
 * Return: number of characters printed
 */
int handle_format(char c, va_list ap)
{
	int j;
	typs typ[] = {
		{"s", _printstr},
		{"c", _printchar},
		{"%", _printperc},
		{"d", _printint},
		{"i", _printint},
		{NULL, NULL}
	};

	for (j = 0; typ[j].typ; j++)
	{
		if (c == typ[j].typ[0])
			return (typ[j].f(ap));
	}
	return (handle_unknown(c));
}

/**
 * _printf - prints formatted output
 * @format: format string
 * @...: optional arguments
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	int i = 0, counter = 0;
	va_list ap;


	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			counter += print_normal(format, &i);
		else
		{
			i++;
			if (!format[i])
			{
				va_end(ap);
				return (-1);
			}

			counter += handle_format(format[i], ap);
			i++;
		}
	}
	va_end(ap);
	return (counter);
}
