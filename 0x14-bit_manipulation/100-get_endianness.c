#include "main.h"

/**
* get_endianness - function that checks the endianness.
* Return: 0 for big, 1 for little endian
*/
int get_endianness(void)
{
	unsigned int a = 1;
	unsigned char *z = (unsigned char *)&a;

	if (*z == 1)
		return (1);
	else
		return (0);
}
