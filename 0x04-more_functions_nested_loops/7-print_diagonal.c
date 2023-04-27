#include "main.h"

/**
 * print_diagonal -  draws a diagonal line on the terminal.
 * @n: input variable
 * Return:void
 */

void print_diagonal(int n)
{
int y, z;
if (n <= 0)
_putchar('\n');
for (y = 0; y < n; y++)
{
for (z = 0; z < y; z++)
{
_putchar(' ');
}
_putchar('\\');
_putchar('\n');
}
}
