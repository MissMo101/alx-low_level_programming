#include "main.h"
/**
 * _abs - Computes the exact value
 * of an integer.
 * @i: input number as an integer
 * Return: exact value
 */
int _abs(int i)
{
	if (i >= 0)
	{
		return (i);
	}
	else
	{
		return (i * -1);
	}
}
