#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 * Return: 0 if the system is big endian, 1 if it is little endian.
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *endian_ptr = (char *)&num;

	/*If the first byte (lowest address) contains the least significant bit, it is little endian. */
	/* Otherwise, it is big endian. */
	return (*endian_ptr == 1);
}
