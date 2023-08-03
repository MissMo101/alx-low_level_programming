#include "main.h"
#include <stddef.h>

/**
 * clear_bit - Sets the value of a bit to 0 at the given index of an integer.
 * @n: Pointer to the unsigned long integer in which the bit will be cleared.
 * @index: The index of the bit to be cleared (starting from 0).
 * Return: 1 if the bit was successfully cleared, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL || index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n &= ~(1UL << index);
	return (1);
}
