#include "main.h"

/**
 * swap_int - function that swaps the values of two integers.
 * @a: swap and stores address of b
 * @b: swap and stores address of a
 * Return: Always 0 (success)
 */

void swap_int(int *a, int *b)
{
int Change;
Change = *b;
*b = *a;
*a = Change;
}
