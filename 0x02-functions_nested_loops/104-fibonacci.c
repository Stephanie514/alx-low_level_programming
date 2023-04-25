#include <stdio.h>
/**
 * main - finds and prints the first 98 Fibonacci numbers
 * starting with 1 and 2, followed by a new line.
 * Return: Always 0 (success)
 */
int main(void)
{
int t = 0;
unsigned long int a = 1, b = 2, next = 0;
printf("%lu, %lu, ", a, b);

while (t < 96)
{
next = a + b;
a = b;
b = next;
printf("%lu", next);
if (t < 95)
printf(", ");
t++;
}
putchar('\n');
return (0);
}
