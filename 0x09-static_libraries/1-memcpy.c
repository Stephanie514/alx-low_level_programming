#include "main.h"

/**
 * _memcpy - function that copies n bytes
 * from memory area src to memory area dest
 *
 * @n: function copies
 * @src: the bytes from memory
 * @dest: to the memory area
 *
 * Return: a pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int y = 0;
while (y < n)
{
dest[y] = src[y];
y++;
}
return (dest);
}
