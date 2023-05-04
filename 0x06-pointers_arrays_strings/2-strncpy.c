#include "main.h"

/**
 * _strncpy - function that copies a string
 * @dest: destination string where the characters will be copied.
 * @src: source string containing the characters to be copied
 * @n: maximum number of characters to be copied from the source string.
 * Return: pointer to destination string
 */

char *_strncpy(char *dest, char *src, int n)
{
int no_of_chars;
for (no_of_chars = 0; no_of_chars < n &&
src[no_of_chars] != '\0'; no_of_chars++)
dest[no_of_chars] = src[no_of_chars];
for (; no_of_chars < n; no_of_chars++)
dest[no_of_chars] = '\0';
return (dest);
}
