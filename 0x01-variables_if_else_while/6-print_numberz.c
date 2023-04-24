#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	int Num;

	for (Num = 0; Num < 10; Num++)
		putchar((Num % 10) + '0');

	putchar('\n');

	return (0);
}
