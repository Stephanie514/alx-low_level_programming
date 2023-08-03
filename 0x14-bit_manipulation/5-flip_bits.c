#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to flip to
 * convert one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to flip.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int total = 0;
	unsigned long int differ = n ^ m;
	int pres  = 63;

	while (pres >= 0)
	{
		if ((differ >> pres) & 1)
			total++;
		pres--;
	}
	return (total);
}
