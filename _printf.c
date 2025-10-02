#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_normal - prints a normal string (no % inside)
 * @str: string to print
 *
 * Return: number of characters printed
 */
int print_normal(const char *str)
{
	int count = 0;

	if (!str)
		return (0);

	while (*str)
	{
		write(1, str, 1);
		count++;
		str++;
	}
	return (count);
}

/**
 * handle_unknown - handles an unknown format specifier
 * @c: character after %
 *
 * Return: number of characters printed
 */
int handle_unknown(char c)
{
	write(1, "%", 1);
	write(1, &c, 1);
	return (2);
}

/**
 * handle_format - handles format specifiers
 * @format: format character
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int handle_format(char format, va_list args)
{
	char c;
	char *s;
	int count = 0;

	if (format == 'c')
	{
		c = va_arg(args, int);
		write(1, &c, 1);
		return (1);
	}
	else if (format == 's')
	{
		s = va_arg(args, char *);
		if (!s)
			s = "(null)";
		return (print_normal(s));
	}
	else if (format == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (handle_unknown(format));
}

/**
 * _printf - custom printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
			{
				va_end(args);
				return (-1); /* case: single '%' at end */
			}
			count += handle_format(*format, args);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}
