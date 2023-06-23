#include "main.h"

/* _isupper - uppercase letters
 * @c: represents the ASCII value of a character
 * Return: returns 1 if c is an uppercase letter,
 * returns 0 if c is not an uppercase letter.
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
