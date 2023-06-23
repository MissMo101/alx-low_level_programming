#include "main.h"
/**
 * _isdigit - checks for digits from 0 to 9
 * @c: Represents the ASCIIvalue of a character
 * Return: returns 1 if c is a digit ,
 * returns 0 if c is not a digit.
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
