#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printstr - prints a string from va_list
 * @ap: A va_list containing the string to print.
 * Return: The number of characters printed.
 */
int _printstr(va_list ap)
{
	char *str = va_arg(ap, char *);
	int counter = 0;

	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		str++;
		counter++;
	}
	return (counter);
}

/**
 * _printchar - prints a single char from va_list
 * @ap: A va_list containing the character to print.
 * Return: Always 1 (the number of characters printed).
 */
int _printchar(va_list ap)
{
	char c = va_arg(ap, int);

	write(1, &c, 1);
	return (1);
}

/**
 * _printperc - prints a percent sign
 * @ap: A va_list (unused, but required by function pointer signature).
 * Return: Always 1 (the number of characters printed).
 */
int _printperc(va_list ap)
{
	(void)ap;
	write(1, "%", 1);
	return (1);
}
