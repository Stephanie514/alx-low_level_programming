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
int r = 0, s;
if (size <= 0)
{
printf("\n");
return;
}
while (r < size)
{
printf("%08x: ", r);
for (s = r; s < r + 10; s += 2)
{
if ((s < size) && ((s + 1) < size))
printf("%02x%02x ", b[s], b[s + 1]);
else
{
printf(" ");
}
}
for (s = r; s < r + 10 && s < size; s++)
{
if (b[s] >= 32 && b[s] <= 126)
printf("%c", b[s]);
else
printf(".");
}
printf("\n");
r += 10;
}
}

