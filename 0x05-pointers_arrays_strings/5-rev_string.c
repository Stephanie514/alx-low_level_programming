#include "main.h"

/**
 * rev_string - function that reverses a string.
 * @s: pointer pointing to the string
 * Return: Always 0 (success)
 */

void rev_string(char *s)
{
int Length, v, Half;
char temp;
for (Length = 0; s[Length] != '\0'; Length++)
;
v = 0;
Half = Length / 2;
while (Half--)
{
temp = s[Length - v - 1];
s[Length - v - 1] = s[v];
s[v] = temp;
v++;
}
}

