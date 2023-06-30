#include <stdio.h>
#include <string.h>
/**
 * infinite_add - a function that adds two numbers.
 * @n1: input value
 * @n2: input value
 * @r: input value
 * @size_r: input value
 * Return: a pointer to the result
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = strlen(n1);
	int len2 = strlen(n2);
	int carry = 0;
	int i, j, k, sum;

	if (len1 + 1 > size_r || len2 + 1 > size_r)
	{
		return (NULL);
	}

	i = len1 - 1;
	j = len2 - 1;
	
	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;

		if (i >= 0)
		{
			sum += n1[i] - '0';
			i--;
		}
		if (j >= 0)
		{
			sum += n2[j] - '0';
			j--;
		}
		r[k] = (sum % 10) + '0';
		carry = sum / 10;
		k++;
	}
	r[k] = '\0';

	return (r);
}
