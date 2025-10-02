#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
