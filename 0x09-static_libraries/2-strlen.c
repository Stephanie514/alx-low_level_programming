#include "main.h"

/**
 *  _strlen - function that returns the length of a string
 * @s: string to be checked
 * Return: Length of the string
 */

int _strlen(char *s)
{
int sLength = 0;
while (s[sLength])
sLength++;
return (sLength);
}
