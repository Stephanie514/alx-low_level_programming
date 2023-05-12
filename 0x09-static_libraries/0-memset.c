#include "main.h"

/**
 * _memset - function that fills memory with a constant byte.
 * @s: memory to be filled
 * @b: character to copy
 * @n: number of times to copy b
 *
 * Return: pointer to memory s
 */

char *_memset(char *s, char b, unsigned int n)
{
unsigned int g;
for (g = 0; g < n; g++)
{
s[g] = b;
}

return (s);
}
