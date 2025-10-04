#include "main.h"

/**
 * _putchar - writes the character c to stdout using a buffer
 * @c: The character to print, or BUF_FLUSH to flush buffer
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	static char buf[OUTPUT_BUF_SIZE];
	static int i;

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
