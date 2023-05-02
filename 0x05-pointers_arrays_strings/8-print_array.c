#include "main.h"
#include <stdio.h>

/**
 * print_array - prints n elements of an array of integers
 * followed by a new line.
 * @a: Input array
 * @n: length of the array
 */

void print_array(int *a, int n)
{
int integers_array;
for (integers_array = 0; integers_array < n; integers_array++)
{
printf("%d", a[integers_array]);
if (integers_array != (n - 1))
{
printf(", ");
}
putchar('\n');
}
}
