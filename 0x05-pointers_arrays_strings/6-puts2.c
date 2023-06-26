#include "main.h"
/**
 * puts - function should print only one character out of two
 * starting with the first one
 * @str: input string
 * Return: print
 */

void puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i += 2;
	}

	_putchar('\n');
}
