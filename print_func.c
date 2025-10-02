#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printstr - prints a string from va_list
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
 */
int _printchar(va_list ap)
{
	char c = va_arg(ap, int);

	
	write(1, &c, 1);
	return (1);
}


/**
 * _printperc - prints a percent sign
 */
int _printperc(va_list ap)
{
	(void)ap;
	write(1, "%", 1);
	return (1);
}
