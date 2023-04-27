#include "main.h"

/**
 * print_most_numbers - prints the numbers from 0 to 9
 * followed by a new line
 * Return: void
 */

void print_most_numbers(void)
{
char r;
for (r = '0'; r <= '9'; r++)
{
if (!(r == '2' || r == '4'))
_putchar(r);
}
_putchar('\n');
}
