#include "main.h"
#include <stdio.h>

/**
 * print_buffer - a function that prints a buffer.
 * @b: buffer
 * @size: the size
 * Return: void
 */

void print_buffer(char *b, int size)
{
int q, r, s;
q = 0;
if (size <= 0)
{
printf("\n");
return;
}
while (q < size)
{
r = size - q < 10 ? size - q : 10;
printf("%08x: ", q);
for (s = 0; s < 10; s++)
{
if (s < r)
printf("%02x", *(b + q + s));
else
printf(" ");
if (s % 2)
{
printf(" ");
}
}
for (s = 0; s < r; s++)
{
int i = *(b + q + s);
if (i < 32 || i > 132)
{
i = '.';
}
printf("%c", i);
}
printf("\n");
q += 10;
}
}
