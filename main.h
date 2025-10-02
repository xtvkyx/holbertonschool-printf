#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printstr(va_list ap);
int _printchar(va_list ap);
int _printperc(va_list ap);

int _printf(const char *format, ...);

/**
 * struct types - Struct to map format specifiers to handler functions
 * @typ: The format specifier character (as a string)
 * @f: The function pointer to the handler
 */
typedef struct types
{
	char *typ;
	int (*f)(va_list);
} typs;

#endif
