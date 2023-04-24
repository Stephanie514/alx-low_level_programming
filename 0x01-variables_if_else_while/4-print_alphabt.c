#include <stdio.h>

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
if (Lowercase == 'e' || Lowercase == 'q')
{
Lowercase += 1;
}
else
{
putchar(Lowercase);
Lowercase += 1;
}
}
putchar('\n');
return (0);
}

