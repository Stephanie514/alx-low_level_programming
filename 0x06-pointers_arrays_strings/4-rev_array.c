#include "main.h"

/**
 * reverse_array - function that reverses the content of an array of integers.
 * @a: pointer to the first element of the array a
 *
 * @n: number of elements in the array
 *
 * Return: void
 */

void reverse_array(int *a, int n)
{
int swap, tally;
n = n - 1;
tally = 0;
while (tally <= n)
{
swap = a[tally];
a[tally++] = a[n];
a[n--] = swap;
}
}
