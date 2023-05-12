#include "main.h"

/**
 * _isdigit - function that checks for a digit
 * @c: Character to br checked
 * Return: 1 for digit character or 0 for anything else
 */

int _isdigit(int c)
{
if (c <= 57 && c >= 48)
{
return (1);
}
return (0);
}

