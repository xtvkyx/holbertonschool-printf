#include <unistd.h>
#include <stdarg.h>
#include "main.h"

<<<<<<< HEAD
/* helper to print normal characters */
int print_normal(const char *format, int *i)
{
	write(1, &format[*i], 1);
	(*i)++;
	return (1);
}

/* helper to handle unknown format */
int handle_unknown(char c)
{
	write(1, "%", 1);
	write(1, &c, 1);
	return (2);
}

/**
 * _printf - prints according to format
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

	if (!format)
		return (0);
=======
/**
 * _printf - prints formatted output
 * @format: format string
 * Return: number of characters printed, or -1 if format is NULL
 */
int _printf(const char *format, ...)
{
	int i = 0, counter = 0;
	va_list ap;

	if (format == NULL)
		return (-1);
>>>>>>> ed4fce4 (0)

	va_start(ap, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
<<<<<<< HEAD
			counter += print_normal(format, &i);
			continue;
=======
			i++;
			if (!format[i])
			{
				va_end(ap);
				return (-1);
			}
			counter += handle_format(format[i], ap);
			i++;
>>>>>>> ed4fce4 (0)
		}

		i++;
		if (!format[i])
			break;

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
			counter += handle_unknown(format[i]);

		i++;
	}

	va_end(ap);
	return (counter);
}
