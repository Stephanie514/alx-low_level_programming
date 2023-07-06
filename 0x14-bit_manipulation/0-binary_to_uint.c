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
int u = 0;
unsigned int B10_data = 0;

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
