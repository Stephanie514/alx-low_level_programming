#include "main.h"

/**
* print_binary - function that converts a binary number
* to an unsigned int.
* @n: number in the in binary to print
* Return: void
*/
void print_binary(unsigned long int n)
{
	int a = 63;
	int num = 0;
	unsigned long int pres;

	while (a >= 0)
	{
		pres = n >> a;
		if (pres & 1)
		{
			_putchar('1');
			num++;
		}
		else if (num)
		{
			_putchar('0');
		}
		a--;
	}

	if (!num)
	{
		_putchar('0');
}
}

