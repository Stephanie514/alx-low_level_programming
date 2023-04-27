#include "main.h"

/**
 * _isupper - function that checks for uppercase character.
 * @c: Character to be checked
 * Return: 1 for uppercase character or 0 for anything else
 */

int _isupper(int c)

{
if (c <= 90 && c >= 65)
{
return (1);
}
return (0);
}
