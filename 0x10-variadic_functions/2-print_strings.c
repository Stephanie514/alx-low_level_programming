#include "variadic_functions.h"

/**
 * print_strings -  function that prints strings, followed by a new line.
 *
 * @separator: string to be printed between the strings
 * @n: number of strings passed to the function
 *
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
unsigned int b;
char *string;
va_list v;
va_start(v, n);
for (b = 0; b < n; b++)
{
string = va_arg(v, char *);
if (!string)
string = "nil";
if (!separator)
printf("%s", string);
else if (separator && b == 0)
printf("%s", string);
else
printf("%s%s", separator, string);
}
printf("\n");
va_end(v);
}
