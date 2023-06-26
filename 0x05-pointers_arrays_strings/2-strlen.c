#include "main.h"
/**
 * int _strlen -  Calculates the length of a string
 * @s: length of a string.
 * Return: length of a string
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
