#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function.
 * @argc: number of arguments given
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
int unit, positn;
int (*location)(int, char **) = main;
unsigned char opstring;
if (argc != 2)
{
printf("Error\n");
exit(1);
}
unit = atoi(argv[1]);
if (unit < 0)
{
printf("Error\n");
exit(2);
}
for (positn = 0; positn < unit; positn++)
{
unsigned char opstring = *(unsigned char *)location;
printf("%.2x", opstring);
if (positn != unit - 1)
{
printf(" ");
}
location++;
}
printf("\n");
return (0);
}
