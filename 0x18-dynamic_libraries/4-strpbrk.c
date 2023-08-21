#include "main.h"

/**
 * _strpbrk -  function that searches a string for any of a set of bytes.
 * @s: the string to be searched
 * @accept: bytes to be searched for
 *
 * Return: pointer to the byte in s that matches one of
 * the bytes in accept, or NULL if no such byte is found
 */

char *_strpbrk(char *s, char *accept)
{
int locat;
while (*s)
{
for (locat = 0; accept[locat]; locat++)
{
if (*s == accept[locat])
return (s);
}
s++;
}
return ('\0');
}
