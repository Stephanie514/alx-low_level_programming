#include "main.h"

/**
 * print_number - function that prints an integer.
 * @n: number to be checked
 * Return: Always 0 (success)
 */

void print_number(int n)
{
int a, b, number, numbers, raised_to;
unsigned int Temp, charn, NUM;
number = 0;
if (n < 0)
{
_putchar('-');
Temp = -n;
}
else
{
Temp = n;
}
NUM = Temp;
while (NUM >= 10)
{
NUM = NUM / 10;
number++;
}
numbers = number + 1;
raised_to = 1;
a = 1;
while (a < numbers)
{
raised_to = raised_to * 10;
a++;
}
b = raised_to;
while (b >= 1)
{
charn = (Temp / b) % 10;
_putchar(charn + '0');
b = b / 10;
}
}
