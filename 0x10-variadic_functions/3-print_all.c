#include "variadic_functions.h"

/**
 * print_all - function that prints anything.
 * @format: list of types of arguments passed to the function
 *
 */

void print_all(const char * const format, ...)
{
int y = 0;
char *stri, *separator = "";
va_list g;
va_start(g, format);
if (format)
{
while (format[y])
{
switch (format[y])
{
case 'c':
printf("%s%c", separator, va_arg(g, int));
break;
case 'i':
printf("%s%d", separator, va_arg(g, int));
break;
case 'f':
printf("%s%f", separator, va_arg(g, double));
break;
case 's':
stri = va_arg(g, char *);
if (!stri)
stri = "(nil)";
printf("%s%s", separator, stri);
break;
default:
break;
}
separator = ", ";
y++;
}
}
va_end(g);
printf("\n");
}
