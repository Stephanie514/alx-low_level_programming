#include <stdio.h>
#include "main.h"

/**
 * main - entry point
 *
 * Description: prints the numbers from 1 to 100
 * followed by a new line.
 * multiples of three print Fizz instead of the
 * number and for the multiples of five print Buzz.
 *
 * Return: always 0
 */

int main(void)
{
int v;
for (v = 1; v <= 100; v++)
{
if (v % 15 == 0)
printf("FizzBuzz");
else if (v % 3 == 0)
printf("Fizz");
else if (v % 5 == 0)
printf("Buzz");
else
printf("%d", v);
if (v < 100)
printf(" ");
}
printf("\n");
return (0);
}

