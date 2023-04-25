#include <stdio.h>

/**
 * main - finds and prints the sum of the even-valued terms
 * followed by a new line.
 * Return: Always 0 (Success)
 */

int main(void)
{
int a;
unsigned long int b, c, next, SUM;
b = 1;
c = 2;
SUM = 0;
for (a = 1; a <= 33; ++a)
{
if (b < 4000000 && (b % 2) == 0)
{
SUM = SUM + b;
}
next = b + c;
b = c;
c = next;
}
printf("%lu\n", SUM);
return (0);
}
