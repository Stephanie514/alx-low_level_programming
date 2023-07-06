#include "main.h"
/**
 * clear_bit - function that sets the value of
 * a bit to 0 at a given index.
 * @n: this is the pointer to the number
 * @index: index of the bit to set
 *
 * Return: 1(success) -1(failure)
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
	{
		return (-1);
	}
	else
	{
		*n = (*n & ~(1UL << index));
		return (1);
	}
}
