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
if (n == 0)
{
printf("\n");
return;
}
for (b = 0; b < n; b++)
{
string = va_arg(v, char *);
if (!string)
string = "(nil)";
if (separator != NULL && b != 0)
printf("%s%s", separator, string);
else
printf("%s", string);
}
printf("\n");
va_end(v);
}

