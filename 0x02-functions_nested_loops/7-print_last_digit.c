#include "main.h"

/**
 * print_last_digit - a function that prints the last digit of a number.
 * @s: Number to be treated
 * Return: Value of the last digit of number
 */

int print_last_digit(int s)
{
int lasdig;
lasdig = s % 10;
if (lasdig < 0)
{
lasdig = lasdig * -1;
}
_putchar(lasdig + '0');
return (lasdig);
}
