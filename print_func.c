/**
* _prinstr - produces string output
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
	int counter;
	counter = 0;
	
	char *str = va_arg(ap, char *);
	while (*str)
	{
		write (1, str, 1);
		str++;
		counter++;
	}
	return (counter);
}

/**
* _princhar - produces char output
* @ap: argument pointer
* Description: a function that produces char output.
* Return: the number of characters printed
*/
#include<unistd.h>
#include<stdio.h>
#include<stdarg.h>
#include"main.h"
int _printchar(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	write (1, &c, 1);
	return (1);
}

/**
* _prinperc - produces percent output
* @ap: argument pointer
* Description: a function that produces percent output.
* Return: the number of characters printed
*/
#include<unistd.h>
#include<stdio.h>
#include<stdarg.h>
#include"main.h"
int _printperc(va_list ap)
{
	write (1, "%", 1);
	return (1);
}
