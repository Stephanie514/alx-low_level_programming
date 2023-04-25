#include "main.h"

/**
 * _isalpha - function that checks for alphabetic character.
 * @c: Character to be checked
 * Return: 1 for alphabetic character or 0 for anything else
 */

int _isalpha(int c)
{
if ((c >= 97 && c <= 122) || (c >= 65 && c <= 97))
{
return (1);
}
return (0);
}
