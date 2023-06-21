#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers
 * starting with 1 and 2
 * Return: 0 (Success)
 */
int main(void)
{
	unsigned long int bef1 = 1, bef2 = 2, aft;
	int i;

		printf("%lu, %lu", bef1, bef2);

	for (i = 3; i <= 98; i++)
	{
		aft = bef1 + bef2;
		printf(", %lu", aft);

		bef1 = bef2;
		bef2 = aft;
	}

	printf("\n");
	return (0);
}
