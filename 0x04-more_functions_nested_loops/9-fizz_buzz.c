#include "main.h"
#include <stdio.h>
/**
 * main - prints numbers from 0 to 100 according to Fizz-Buzz test,
 * But for multiples of three print Fizz instead of the number
 * and for the multiples of five print Buzz.
 * Return: Always 0
 */

int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			printf("FizzBuzz ");
		}
		else if (i % 3 == 0)
		{
			printf("Fizz ");
		}
		else if (i % 5 == 0)
		{
			printf("Buzz ");
		}
		else
		{
			printf("%d ", i);
		}
	}

	printf("\n");

	return (0);
}
