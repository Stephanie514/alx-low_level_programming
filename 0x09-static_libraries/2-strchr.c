#include "main.h"

/**
 * _strchr - function that gets the length of a prefix substring.
 * @s: string to be searched
 * @c: character to be located
 *
 * Return: If c is not found, NULL, if c is found - pointer to first occurence
 */

char *_strchr(char *s, char c)
{
int str;
for (str = 0; s[str] >= '\0'; str++)
{
if (s[str] == c)
return (s + str);
}
return ('\0');
}
