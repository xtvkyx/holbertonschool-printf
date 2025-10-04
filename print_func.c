#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printstr - prints a string from va_list
 * @ap: A va_list containing the string to print.
 * @flags: flag struct (unused)
 * Return: The number of characters printed.
 */
int _printstr(va_list ap, flags_t flags)
{
	char *str = va_arg(ap, char *);
	int counter = 0;

	(void)flags;

	if (!str)
		str = "(null)";
	while (*str)
	{
		_putchar(*str);
		str++;
		counter++;
	}
	return (counter);
}

/**
 * _printchar - prints a single char from va_list
 * @ap: A va_list containing the character to print.
 * @flags: flag struct (unused)
 * Return: Always 1 (the number of characters printed).
 */
int _printchar(va_list ap, flags_t flags)
{
	char c = va_arg(ap, int);

	(void)flags;

	_putchar(c);
	return (1);
}

/**
 * _printperc - prints a percent sign
 * @ap: A va_list (unused, but required by function pointer signature).
 * @flags: flag struct (unused)
 * Return: Always 1 (the number of characters printed).
 */
int _printperc(va_list ap, flags_t flags)
{
	(void)ap;
	(void)flags;
	_putchar('%');
	return (1);
}

/**
 * _printS - prints a string, non-printable chars as \xHEX
 * @ap: A va_list containing the string to print.
 * @flags: flag struct (unused)
 * Return: count
 */
int _printS(va_list ap, flags_t flags)
{
	char *str = va_arg(ap, char *);
	int i = 0, count = 0;
	char hex[] = "0123456789ABCDEF";

	(void)flags;

	if (!str)
		str = "(null)";

	while (str[i])
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			_putchar(hex[(str[i] / 16) % 16]);
			_putchar(hex[str[i] % 16]);
			count += 4;
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
		i++;
	}

	return (count);
}

/**
* _printptr - prints a pointer address in hexadecimal
* @ap: va_list containing the pointer
* @flags: flag struct (unused)
* Return: number of characters printed
*/
int _printptr(va_list ap, flags_t flags)
{
	unsigned long ptr = (unsigned long)va_arg(ap, void *);
	char hex[] = "0123456789abcdef";
	char buffer[32];
	int i = 0, count = 0;

	(void)flags;

	if (!ptr)
	{
		_putchar('(');
		_putchar('n');
		_putchar('i');
		_putchar('l');
		_putchar(')');
		return (5);
	}

	while (ptr > 0)
	{
		buffer[i++] = hex[ptr % 16];
		ptr /= 16;
	}

	_putchar('0');
	_putchar('x');
	count += 2;

	while (i--)
	{
		_putchar(buffer[i]);
		count++;
	}

	return (count);
}
