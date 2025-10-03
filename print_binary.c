#include "main.h"
#include <stdarg.h>

/**
 * _printbin - prints an unsigned int as binary
 * @ap: va_list containing the unsigned int
 * Return: number of characters printed
 */
int _printbin(va_list ap)
{
    unsigned int n = va_arg(ap, unsigned int);
    int count = 0;
    int bits[32];
    int i;

    if (n == 0)
        return (_putchar('0'));

    for (i = 0; n > 0; i++)
    {
        bits[i] = n % 2;
        n /= 2;
    }

    while (i--)
        count += _putchar(bits[i] + '0');

    return (count);
}
