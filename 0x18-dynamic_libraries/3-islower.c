#include "main.h"

/**
 * _islower - function that checks for lowercase character.
 *@g: Character is to be checked
 * Return: 1 for a lowercase character or 0 for anything else
 */

int _islower(int g)
{
if (g >= 97 && g <= 122)
{
return (1);
}
return (0);
}


