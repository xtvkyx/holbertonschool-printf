#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _printstr(va_list ap)
{
	int counter = 0;
	char *str = va_arg(ap, char *);

	if (!str)
		return (0);
	while (*str)
	{
		write(1, str, 1);
		str++;
		counter++;
	}
	return (counter);
}

int _printchar(va_list ap)
{
	char c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int _printperc(va_list ap)
{
	(void)ap;
	write(1, "%", 1);
	return (1);
}
