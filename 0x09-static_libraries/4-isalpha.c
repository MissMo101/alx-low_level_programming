#include "main.h"
#include <stdio.h>
/**
 * _isalpha - Shows 1 if a input is a
 * letter, Another case shows 0
 * @c: The character in ASCII code
 * Return: 1 for letters, 0 for the rest
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
	return (1);
	}
	return (0);
}

int main(void)
{
	char ch = 'a';

	if (_isalpha(ch))
	{
		printf("%c is an alphabetic character.\n", ch);
	}
	else
	{
		printf("%c is not an alphabetic character.\n", ch);
	}

	return (0);
}
