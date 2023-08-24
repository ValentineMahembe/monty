#include "monty.h"

/**
 * _isdigit - checks if a string contains only digits
 * @str: string to be checked
 *
 * Return: 1 if the string contains only digits, 0 otherwise
 */
int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
