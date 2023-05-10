#include "main.h"

int real_prime_number(int n, int g);

/**
 * is_prime_number - function that returns 1 if the
 * input integer is a prime number
 *
 * @n: number to be checked
 *
 * Return: 0 if not prime, 1 if prime
 */

int is_prime_number(int n)
{
if (n <= 1)
return (0);
return (real_prime_number(n, n - 1));
}

/**
 * real_prime_number - calculates the number if it is prime, recursion
 * @g: iterator
 * @n: number to be checked
 *
 * Return: 0 if not prime, 1 if prime
 */

int real_prime_number(int n, int g)
{
if (g == 1)
return (1);
if (n % g == 0 && g > 0)
return (0);
return (real_prime_number(n, g - 1));
}

