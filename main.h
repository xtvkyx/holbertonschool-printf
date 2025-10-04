#ifndef MAIN_H
#define MAIN_H

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#include <stdarg.h>
#include <unistd.h>

/**
 * struct flags - structure for flag characters
 * @plus: '+' flag
 * @space: ' ' flag
 * @hash: '#' flag
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct types - structure for specifiers and functions
 * @id: specifier
 * @f: function pointer
 */
typedef struct types
{
	char *id;
	int (*f)(va_list, flags_t);
} typs;

int _putchar(char c);
int _printf(const char *format, ...);

int _printstr(va_list list, flags_t flags);
int _printchar(va_list list, flags_t flags);
int _printperc(va_list list, flags_t flags);
int _printint(va_list list, flags_t flags);
int _printunsigned(va_list list, flags_t flags);
int _printoctal(va_list list, flags_t flags);
int _printhex(va_list list, flags_t flags);
int _printHEX(va_list list, flags_t flags);
int _printbin(va_list list, flags_t flags);
int _printS(va_list list, flags_t flags);
int _printptr(va_list list, flags_t flags);

int print_number(int n);
int print_unsigned_base(unsigned int n, int base, int uppercase);

flags_t get_flags(const char *format, int *i);

#endif
