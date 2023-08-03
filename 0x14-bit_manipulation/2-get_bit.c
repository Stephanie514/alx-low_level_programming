#include "main.h"
/**
 * get_bit - function that returns the value of a bit
 * at a given index.
 * @n: the number to search for
 * @index: index of the bit you want to get
 *
 * Return: value of the bit at index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int dec_data;
	unsigned int d = 0;

	if (index > 63)
		return (-1);
	d = 0;
	do {
		dec_data = (n >> d) & 1;
		d++;
	} while (d <= index);
	return (dec_data);
}
