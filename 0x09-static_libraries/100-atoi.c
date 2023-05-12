#include "main.h"

/**
 * _atoi - function that convert a string to an integer
 * @s: string to be converted
 *
 * Return: Integer value of the converted string
 */

int _atoi(char *s)
{
int zc = 1;
unsigned int dig = 0;
do {
if (*s == '-')
zc *= -1;
else if (*s >= '0' && *s <= '9')
dig = (dig * 10) + (*s - '0');
else if (dig > 0)
break;
} while (*s++);
return (dig *zc);
}
