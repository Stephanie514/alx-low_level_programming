#include "main.h"

/**
 * _strspn - function that gets the length of a prefix substring.
 * @s: string to be searched
 * @accept: prefix to be measured
 *
 * Return: number of bytes in the initial segment
 * of s which consist only of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
unsigned int mem_stor = 0;
int locat;
while (*s)
{
for (locat = 0; accept[locat]; locat++)
{
if (*s == accept[locat])
{
mem_stor++;
break;
}
else if (accept[locat + 1] == '\0')
return (mem_stor);
}
s++;
}
return (mem_stor);
}
