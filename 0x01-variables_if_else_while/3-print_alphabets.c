#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
int Lowercase = 'a';
int Uppercase = 'A';
while (Lowercase <= 'z')
{
putchar(Lowercase);
Lowercase += 1;
}
while (Uppercase <= 'Z')
{
putchar(Uppercase);
Uppercase += 1;
}
putchar('\n');
return (0);
}
