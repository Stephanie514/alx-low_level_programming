#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - this prints the minimum number of coins to
 * make change for an amount of money
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Success), 1 if not success
 */
int main(int argc, char *argv[])
{
int dig, d, soln;
int coin[] = {25, 10, 5, 2, 1};
if (argc != 2)
{
printf("Error\n");
return (1);
}
dig = atoi(argv[1]);
soln = 0;
if (dig < 0)
{
printf("0\n");
return (0);
}
for (d = 0; d < 5 && dig >= 0; d++)
{
while (dig >= coin[d])
{
soln++;
dig -= coin[d];
}
}
printf("%d\n", soln);
return (0);
}
