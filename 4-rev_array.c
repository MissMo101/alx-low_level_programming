#include "main.h"
/**
 * reverse_array - a function that reverses an array of integers.
 * @a: array
 * @n: number of elements of the array
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i, t;

	for (i = 0; i < n--; i++)
	{
		t = a[i];
		a[n] = a[i];
		a[n] = t;
	}
}
