#include "variadic_functions.h"

/**
 * print_numbers - function that prints numbers, followed by a new line.
 * @separator: the string to be printed between numbers
 * @n: number of integers passed to the function
 * Return: void
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
unsigned int a;
va_list b;
va_start(b, n);
for (a = 0; a < n; a++)
{
if (separator == 0)
printf("%d", va_arg(b, int));
else if (separator && a == 0)
printf("%d", va_arg(b, int));
else
printf("%s%d", separator, va_arg(b, int));
}
va_end(b);
printf("\n");
}
