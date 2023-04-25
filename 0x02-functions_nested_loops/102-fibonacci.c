#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers, starting with 1 and 2
 * followed by a new line
 * Return: Always 0 (success)
 */

int main(void)
{
long int a, b, c, next;
a = 1;
b = 2;
printf("%ld, %ld", a, b);
for (a = 3; a <= 50; ++a)
{
next = b + c;
printf(", %ld", next);
c = b;
b = next;
}
printf("\n");
return (0);
}
