#include "main.h"

/**
 * print_alphabet_x10 - make alphabet x10 in lowercase
 * Return: void
 */

void print_alphabet_x10(void)
{
char alph;
int h;
h = 0;
while (h < 10)
{
for (alph = 'a'; alph <= 'z'; alph++)
{
_putchar(alph);
}
_putchar('\n');
h++;
}
}
