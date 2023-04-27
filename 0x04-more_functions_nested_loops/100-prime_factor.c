#include <stdio.h>
#include "main.h"
/**
 * main - prints the largest prime factor number 612852475143
 * Return: Always 0
 */

int main(void)
{
unsigned long int s, t = 612852475143;
for (s = 3; s < 782849; s = s + 2)
{
while ((t % s == 0) && (t != s))
t = t / s;
}
printf("%lu\n", t);
return (0);
}
