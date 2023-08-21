#include "main.h"

/**
 * _strstr - function that locates a substring.
 * @haystack: string to be searched
 * @needle: substring to be located
 *
 * Return: pointer to the beginning of the located
 * substring, or NULL if the substring is not found.
 */

char *_strstr(char *haystack, char *needle)
{
int locat;
if (*needle == 0)
return (haystack);
while (*haystack)
{
locat = 0;
if (haystack[locat] == needle[locat])
{
do {
if (needle[locat + 1] == '\0')
return (haystack);
locat++;
} while (haystack[locat] == needle[locat]);
}
haystack++;
}
return ('\0');
}

