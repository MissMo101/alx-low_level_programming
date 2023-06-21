#include "main.h"
/**
 * prints_times_table - prints the n times table, starting from 0
 * @n: number of the times table
 */

void print_times_table(int n)
{
	if (n < 0 || n > 15)
	{
		return;
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			int result = i * j;

			printf("%-4d", result);
		}
		printf("\n");
	}
}

int main(void)
{

	int n = 10;

	print_times_table(n);
	return (0);
}

