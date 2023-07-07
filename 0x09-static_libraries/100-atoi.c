#include "main.h"
/**
 * _atoi -  a function that convert a string to an integer.
 * @s: string to be converted
 * Return: the converted integer value
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
	{
		i++;
	}

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10 + (s[i] - '0');
			i++;
		}
		else
		{
			break;
		}
	}

	return (result * sign);
}
