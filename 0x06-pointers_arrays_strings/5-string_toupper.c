#include "main.h"

/**
 * string_toupper - function that changes all
 * lowercase letters of a string to uppercase.
 * @b: pointer to uppercase string
 * Return: pointer to uppercase string
 */

char *string_toupper(char *b)
{
int stringLength;
stringLength = 0;
while (b[stringLength] != '\0')
{
if (b[stringLength] >= 97 && b[stringLength] <= 122)
{
b[stringLength] = b[stringLength] - 32;
}
stringLength++;
}
return (b);
}
