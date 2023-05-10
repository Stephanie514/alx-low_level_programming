#include "main.h"

/**
 * _strlen_recursion - function that returns the length of a string
 * @s: string to be measured
 *
 * Return: length of string
 */

int _strlen_recursion(char *s)
{
int lengthstr = 0;
if (*s)
{
lengthstr++;
lengthstr = +_strlen_recursion(s + 1); lengthstr++;
}
return (lengthstr);
}

