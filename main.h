#ifndef MAIN_H
#define MAIN_H
#include<stdarg.h>
/**
* struct typ - Struct types
* @types: The type
* @f: The function associated
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
