#include <stdio.h>
/**
 * main - finds and prints the first 98 Fibonacci numbers
 * starting with 1 and 2, followed by a new line.
 * Return: Always 0 (success)
 */
int main(void)
{
int t = 0;
unsigned long int a = 0, b = 1, next = 0;
while (t < 98)
{
next = a + b;
a = b;
b = next;
printf("%lu", next);
if (t < 98)
printf(", ");
t++;
}
putchar('\n');
return (0);
}
