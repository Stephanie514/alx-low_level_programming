#include "main.h"

/**
 * _strncat - function that concatenates two strings.
 * @dest: destination string pointer
 * @src: source string pointer
 * @n: number of bytes
 * Return: pointer to destination string
 */

char *_strncat(char *dest, char *src, int n)
{
int stringLength, a;
stringLength = 0;
while (dest[stringLength] != '\0')
{
stringLength++;
}
for (a = 0; a < n && src[a] != '\0'; a++, stringLength++)
{
dest[stringLength] = src[a];
}
dest[stringLength] = '\0';
return (dest);
}
