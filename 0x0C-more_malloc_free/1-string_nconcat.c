#include <stdlib.h>
#include "main.h"

/**
 * *string_nconcat - function that concatenates two strings.
 * @s1: the string to append to
 * @s2: the string to concatenate
 * @n: bytes from s2 to s1
 *
 * Return: pointer to the resulting string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *b;
unsigned int r = 0, s = 0, length1 = 0, length2 = 0;
while (s1 && s1[length1])
length1++;
while (s2 && s2[length2])
length2++;
if (n < length2)
b = malloc(sizeof(char) * (length1 + n + 1));
else
b = malloc(sizeof(char) * (length1 + length2 + 1));
if (!b)
return (NULL);
while (r < length1)
{
b[r] = s1[r];
r++;
}
while (n < length2 && r < (length1 + n))
b[r++] = s2[s++];
while (n >= length2 && r < (length1 + length2))
b[r++] = s2[s++];
b[r] = '\0';
return (b);
}

