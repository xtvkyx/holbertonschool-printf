#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

<<<<<<< HEAD

int _printint(va_list ap);
int print_number(long int n);
int _putchar(char c);
=======
int _putchar(char c);
int _printf(const char *format, ...);
>>>>>>> 711c7f5ac974bb78a3a5e2b73c288a30b696b3eb

int _printstr(va_list ap);
int _printchar(va_list ap);
int _printperc(va_list ap);
<<<<<<< HEAD
int _printf(const char *format, ...);
=======

int _printint(va_list ap);
int print_number(long int n);
>>>>>>> 711c7f5ac974bb78a3a5e2b73c288a30b696b3eb

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
