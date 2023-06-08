#include "main.h"

/**
* get_bit - function that returns the value of a
*           bit at a given index.
* @n: number to search
* @index: index, starting from 0 of the bit you want to get
*
* Return: value of the bit at index or -1 if an error occured
*/

int get_bit(unsigned long int n, unsigned int index)
{
	int data_bit;
	int a = 0;

	if (index > 63)
		return (-1);

	do {
		data_bit = (n & (1 << a)) != 0;
		a++;
	} while (a <= (int)index);
	return (data_bit);
}
