#include <stdio.h>

/**
 * main - program that prints all arguments it receives.
 * @argc: the number of arguments
 * @argv: the array
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
int g;
for (g = 0; g < argc; g++)
{
printf("%s\n", argv[g]);
}
return (0);
}
