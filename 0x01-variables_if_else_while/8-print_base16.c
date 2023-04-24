#include <stdio.h>

/**
 * main - Print all the numbers of base 16 in lowercase.
 *
 * Return: Always 0 (success)
 */
int main(void)
{
int Num;
char letter;

for (Num = 0; Num < 10; Num++)
putchar ((Num % 10) + '0');
for (letter = 'a'; letter <= 'f'; letter++)
putchar(letter);
putchar('\n');
return (0);
}
