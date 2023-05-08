#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - function that prints the sum of
 * the two diagonals of a square matrix of integers.
 * @a: matrix of integers
 * @size: matrix size
 * Return: 0
 */

void print_diagsums(int *a, int size)
{
int locat, Add1 = 0, Add2 = 0;
for (locat = 0; locat < size; locat++)
{
Add1 += a[locat];
a += size;
}
a -= size;
for (locat = 0; locat < size; locat++)
{
Add2 += a[locat];
a -= size;
}
printf("%d, %d\n", Add1, Add2);
}

