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
	int i = 0, j, counter = 0;
	va_list ap;
	typs typ[] = {
		{"s", _printstr},
		{"c", _printchar},
		{"%", _printperc},
		{NULL, NULL}
	};
	va_start(ap, format);
	
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
			counter++;
		}
		if (format[i] == '%')
		{
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
			if (typ[j].typ == NULL)
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				counter += 2;
			}
			
			i++;
		}
	}
	va_end(ap);
	return (counter);
}
