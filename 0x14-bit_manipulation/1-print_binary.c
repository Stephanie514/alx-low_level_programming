#include "main.h"

/**
 * print_binary - function that prints the binary
 * representation of a number.
 * @n: this is the number to print
 */
void print_binary(unsigned long int n)
{
int v, total = 0;
unsigned long int presnt;

for (v = 63; v >= 0; v--)
{
	presnt = n >> v;
	if (presnt & 1)
	{
		_putchar('1');
		total++;
	}
	else if (total)
		_putchar('0');
}
if (!total)
	_putchar('0');
}
