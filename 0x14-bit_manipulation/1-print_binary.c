#include "main.h"
/**
 * print_binary - function that prints the binary
 * representation of a number.
 * @n: this is the number to print
 */
void print_binary(unsigned long int n)
{
	int v = 63;
	int total = 0;
	unsigned long int pres;

	while (v >= 0)
	{
		pres = n >> v;
		if (pres & 1)
		{
			_putchar('1');
			total++;
		}
		else if (total)
		{
			_putchar('0');
		}
		v--;
	}
	if (!total)
	{
		_putchar('0');
	}
}
