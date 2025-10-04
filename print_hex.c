#include "main.h"
#include <stdarg.h>

/**
 * _printhex - handles %x (lowercase)
 */
int _printhex(va_list ap, flags_t flags)
{
	unsigned int n = va_arg(ap, unsigned int);
	int count = 0;

	if (flags.hash && n != 0)
	{
		_putchar('0');
		_putchar('x');
		count += 2;
	}

	count += print_unsigned_base(n, 16, 0);
	return (count);
}

/**
 * _printHEX - handles %X (uppercase)
 */
int _printHEX(va_list ap, flags_t flags)
{
	unsigned int n = va_arg(ap, unsigned int);
	int count = 0;

	if (flags.hash && n != 0)
	{
		_putchar('0');
		_putchar('X');
		count += 2;
	}

	count += print_unsigned_base(n, 16, 1);
	return (count);
}
