#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int print_normal(const char *format, int *i)
{
	write(1, &format[*i], 1);
	(*i)++;
	return (1);
}

int handle_unknown(char c)
{
	write(1, "%", 1);
	write(1, &c, 1);
	return (2);
}

int handle_format(char c, va_list ap)
{
	int j;
	typs typ[] = {
		{"s", _printstr},
		{"c", _printchar},
		{"%", _printperc},
		{NULL, NULL}
	};

	for (j = 0; typ[j].typ; j++)
	{
		if (c == typ[j].typ[0])
			return typ[j].f(ap);
	}
	return handle_unknown(c);
}

/**
 * _printf - prints formatted output
 */
int _printf(const char *format, ...)
{
	int i = 0, counter = 0;
	va_list ap;

	if (!format)
		return (0);

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			counter += print_normal(format, &i);
		else
		{
			i++;
			if (!format[i])
				break;
			counter += handle_format(format[i], ap);
			i++;
		}
	}
	va_end(ap);
	return (counter);
}
