#include "main.h"

/**
 * binary_to_uint - function that converts a binary
 * number to an unsigned int.
 * @b: points to a string of binary numbers
 *
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
int h;
unsigned int data_decimal = 0;

if (h == NULL)
	return (0);
for (h = 0; b[h] != '\0'; h++)
{
	if (b[h] < '0' || b[h] > '1')
		return (0);
	data_decimal = (data_decimal << 1) + (b[h] - '0');
}
return (data_decimal);
}
