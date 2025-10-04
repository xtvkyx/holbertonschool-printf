#ifndef MAIN_H
#define MAIN_H

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#include <stdarg.h>
#include <unistd.h>

/**
 * struct types - structure for specifiers and functions
 * @id: specifier
 * @f: function pointer
 */
typedef struct types
{
    char *id;
    int (*f)(va_list);
} typs;

int _putchar(char c);
int _printf(const char *format, ...);

int _printstr(va_list list);
int _printchar(va_list list);
int _printperc(va_list list);

int print_number(int n);
int _printint(va_list list);

int _printbin(va_list list);

int _printunsigned(va_list list);
int _printoctal(va_list list);
int _printhex(va_list list);
int _printHEX(va_list list);
int print_unsigned_base(unsigned int n, int base, int uppercase);
int _printS(va_list list);
int _printptr(va_list list);
#endif
