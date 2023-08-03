#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 * Return: 0 if the system is big endian, 1 if it is little endian.
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *endian_ptr = (char *)&num;

	return (*endian_ptr == 1);
}
