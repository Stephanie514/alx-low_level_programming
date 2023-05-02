#include "main.h"

/**
 * puts2 - function that prints every other character of a string
 * starting with the first character, followed by a new line.
 * @str: used string reference
 * Return: Always 0 (success)
 */

void puts2(char *str)
{
int r = 0;
while (str[r] != '\0')
{
if (r % 2 == 0)
{
_putchar(str[r]);
}
r++;
}
_putchar('\n');
}
