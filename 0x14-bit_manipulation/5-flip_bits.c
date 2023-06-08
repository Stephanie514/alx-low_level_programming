#include "main.h"

/**
 * flip_bits - function that returns the number of bits you would
 * need to flip to get from one number to another.
 * @n: 1st number
 * @m: 2nd number
 *
 * Return: number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int num = 0;
	unsigned long int diff = n ^ m;
	int a = 63;

	while (a >= 0)
	{
		if ((diff >> a) & 1)
			num++;
		a--;
	}
	return (num);
}
