#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, j, counter = 0;
	va_list ap;
	typs typ[] = {
		{"s", _printstr},
		{"c", _printchar},
		{"%", _printperc},
		{NULL, NULL}
	};

	if (format == NULL)
		return (0);

	va_start(ap, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			counter++;
			i++;
			continue;
		}

		i++;
		if (!format[i])
		{
			va_end(ap);
			return (counter);
		}

		j = 0;
		while (typ[j].typ)
		{
			if (format[i] == typ[j].typ[0])
			{
				counter += typ[j].f(ap);
				break;
			}
			j++;
		}

		if (!typ[j].typ)
		{
			write(1, "%", 1);
			write(1, &format[i], 1);
			counter += 2;
		}

		i++;
	}

	va_end(ap);
	return (counter);
}
