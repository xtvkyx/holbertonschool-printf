/**
* _printstr - produces string output
* @ap: argument pointer
* Description: a function that produces string output.
* Return: the number of characters printed
*/
#include<unistd.h>
#include<stdio.h>
#include<stdarg.h>
#include"main.h"
int _printstr(va_list ap)
{
	int counter = 0;
	char *str = va_arg(ap, char *);

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		write (1, str, 1);
		str++;
		counter++;
	}
	return (counter);
}
/**
* _printchar - produces char output
* @ap: argument pointer
* Description: a function that produces char output.
* Return: the number of characters printed
*/
int _printchar(va_list ap)
{
	char c = va_arg(ap, int);
	write (1, &c, 1);
	return (1);
}

/**
* _printperc - produces percent output
* @ap: argument pointer
* Description: a function that produces percent output.
* Return: the number of characters printed
*/
int _printperc(va_list ap)
{
	(void)ap;	
	write (1, "%", 1);
	return (1);
}
