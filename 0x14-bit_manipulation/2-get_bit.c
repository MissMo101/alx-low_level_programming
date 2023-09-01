#include "main.h"
#include <stdio.h>

/**
 * get_bit -  returns the value of a bit at a given index.
 * @n: the integer in which the bit value will be retrieved.
 * @index: the index of the bit to be retrieved.
 * Return: the bit value.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
