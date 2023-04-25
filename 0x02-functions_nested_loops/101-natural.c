#include <stdio.h>

/**
 * main - computes and prints the sum of all the multiples
 * of 3 or 5 below 1024
 * Return: Always 0 (success)
 */
int main(void)
{
unsigned long int SUM3, SUM5, SUM;
int a;
SUM3 = 0;
SUM5 = 0;
SUM = 0;
for (a = 0; a < 1024; ++a)
{
if ((a % 3) == 0)
{
SUM3 = SUM3 + a;
}
else if ((a % 5) == 0)
{
SUM5 = SUM5 + a;
}
}
SUM = SUM3 + SUM5;
printf("%lu\n", SUM);
return (0);
}
