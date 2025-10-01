/**
* _printf - produces output according to a format
* @format: format
* Description: a function that produces output according to a format.
* Return: the number of characters printed
*/
#include<unistd.h>
#include<stdio.h>
#include<stdarg.h>
#include"main.h"
int _printf(const char *format, ...)
{
	int i = 0, j, counter;
	va_list ap;
	typs typ[] = {
		{"s", _printstr},
		{"c", _printchar},
		{"%", _printperc},
		{NULL, NULL}
	};
	va_start(ap, format);

	counter = 0;
	while (*format)
	{
		while (format[i] != '%')
		{
			write (1, format[i], 1);
		}
		if (format [i + 1] == typ[i].f[0] && typ[1] == '\0')
			typ[i].f(ap);
		i++;
		counter++;
	}
	return (counter);
}
