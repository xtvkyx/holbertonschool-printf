#include "main.h"
#include <stdarg.h>

/**
 * _printhex - handles %x (lowercase)
 */
int _printhex(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	return (print_unsigned_base(n, 16, 0));
}

/**
 * _printHEX - handles %X (uppercase)
 */
int _printHEX(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	return (print_unsigned_base(n, 16, 1));
}
