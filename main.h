#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct typ - Struct for format specifiers
 * @typ: The format type as a string
 * @f: Pointer to the function that handles this type
 */
typedef struct typ
{
	char *typ;
	int (*f)(va_list);
} typs;

int _printstr(va_list ap);
int _printchar(va_list ap);
int _printperc(va_list ap);
int _printf(const char *format, ...);

#endif
