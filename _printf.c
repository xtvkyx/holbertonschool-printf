#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_normal - prints a single character from the format string
 * @format: the format string
 * @i: pointer to current index
 * Return: number of characters printed (always 1)
 */
int print_normal(const char *format, int *i)
{
	_putchar(format[*i]);
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
	_putchar('%');
	_putchar(c);
	return (2);
}

/**
 * handle_format - handles valid format specifiers
 * @c: the format character
 * @ap: va_list of arguments
 * @flags: flags struct
 * Return: number of characters printed
 */
int handle_format(char c, va_list ap, flags_t flags)
{
	int j;
	typs typ[] = {
		{"s", _printstr},
		{"S", _printS},
		{"c", _printchar},
		{"%", _printperc},
		{"d", _printint},
		{"i", _printint},
		{"b", _printbin},
		{"u", _printunsigned},
		{"o", _printoctal},
		{"x", _printhex},
		{"X", _printHEX},
		{"p", _printptr},
		{NULL, NULL}
	};

	for (j = 0; typ[j].id; j++)
	{
		if (c == typ[j].id[0])
			return (typ[j].f(ap, flags));
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
	flags_t flags;

	if (!format)
		return (-1);

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			counter += print_normal(format, &i);
		}
		else
		{
			i++;
			if (!format[i])
				return (-1);

			flags = get_flags(format, &i);

			if (!format[i])
				break;

			counter += handle_format(format[i], ap, flags);
			i++;
		}
	}
	va_end(ap);
	_putchar(BUF_FLUSH);
	return (counter);
}
