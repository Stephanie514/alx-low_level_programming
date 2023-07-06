#include "main.h"
/**
 * set_bit - function that sets the value of a bit
 * to 1 at a given index.
 * @n: pointer to the number
 * @index: index of the bit that is to set to 1
 *
 * Return: 1 (success), -1 (failure)
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
	{
		return (-1);
	}
	else
	{
		*n = *n | (1UL << index);
		return (1);
	}
}
