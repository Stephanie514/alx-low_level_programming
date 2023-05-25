#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - function that returns the sum of all its parameters.
 *
 * @n: number of the arguments
 * Return: sum of all its parameters, if n == 0, return 0
 */

int sum_them_all(const unsigned int n, ...)
{
va_list b;
unsigned int g;
int SUM;
SUM = 0;
va_start(b, n);
for (g = 0; g < n; g++)
SUM = SUM + va_arg(b, int);
va_end(b);
return (SUM);
}
