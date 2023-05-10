#include "main.h"

int real_sqrt_recursion(int n, int g);
/**
 * _sqrt_recursion - function that returns the natural square root of a number.
 * @g: the square root calculated currently
 * @n: square root is calculated for this number
 * Return: the square root calculated
 */

int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
return (real_sqrt_recursion(n, 0));
}

/**
 * real_sqrt_recursion - helper function for calculating the square root recursively
 *
 * @n: square root is calculated for this number
 * @g: the square root calculated currently
 * Return: the square root calculated
 */

int real_sqrt_recursion(int n, int g)
{
if (g * g > n)
return (-1);
if (g * g == n)
return (g);
return (real_sqrt_recursion(n, g + 1));
}

