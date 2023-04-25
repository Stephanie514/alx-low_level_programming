#include "main.h"

/**
 * jack_bauer - function that prints every minute of the day of Jack Bauer
 * Return: ...
 */

void jack_bauer(void)
{
int g, h, i, j;
for (g = 0; g <= 2; g++)
{
for (h = 0; h <= 9; h++)
{
if ((g <= 1 && h <= 9) || (g <= 2 && h <= 3))
{
for (i = 0; i <= 5; i++)
{
for (j = 0; j <= 9; j++)
{
_putchar(g + '0');
_putchar(h + '0');
_putchar(58);
_putchar(i + '0');
_putchar(j + '0');
_putchar('\n');
}
}
}
}
}
}
