#include "main.h"

/**
* binary_to_uint - function that converts a binary
* number to an unsigned int.
* @b: a string which point to a string of 0 and 1 chars
*
* Return: the converted number, or 0 if b is NULL, or there is
*         one or more chars in the string b that is not 0 or 1
*/
unsigned int binary_to_uint(const char *b)
{
	int u = 0;
	unsigned int B10_data;

	B10_data = 0;

	if (!b)
		return (0);
	while (b[u])
	{
		if (!(b[u] == '0' || b[u] == '1'))
			return (0);
		B10_data = (B10_data << 1) + (b[u] - '0');
		u++;
	}
	return (B10_data);
}

