#include "main.h"

/**
 * print_square - prints a square, followed by a new line.
 * @size: Size of the square
 * Return: void
 */
void print_square(int size)
{
int f, g;
if (size <= 0)
_putchar('\n');
for (f = 0; f < size; f++)
{
for (g = 0; g < (size); g++)
{
_putchar('#');
}
_putchar('\n');
}
}
