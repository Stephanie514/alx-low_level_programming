#include <stdio.h>
#include <ctype.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
int Lowercase = 'a';
while (Lowercase <= 'z')
{
putchar(Lowercase);
Lowercase += 1;
}
putchar('\n');
return (0);
}
