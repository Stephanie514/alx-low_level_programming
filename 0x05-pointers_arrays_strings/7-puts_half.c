#include "main.h"

/**
 * puts_half - function that prints half of a string
 * followed by a new line.
 *
 * @str: Input string
 */

void puts_half(char *str)
{
int Whole_string, Half_string;
Whole_string = 0;
while (str[Whole_string] != '\0')
Whole_string++;
Half_string = Whole_string / 2;
if (Whole_string % 2 == 1)
Half_string++;
while (Half_string < Whole_string)
{
_putchar(str[Half_string]);
Half_string++;
}
_putchar('\n');
}
