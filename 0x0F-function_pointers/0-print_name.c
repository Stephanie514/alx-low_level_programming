#include <stdio.h>
#include <stdlib.h>

/**
 * print_name - function that prints a name.
 *
 * @name: name printed
 *
 * @f: pointer to the function which prints a name
 *
 */

void print_name(char *name, void (*f)(char *))
{
if (name == NULL || f == NULL)
return;
(*f)(name);
}
