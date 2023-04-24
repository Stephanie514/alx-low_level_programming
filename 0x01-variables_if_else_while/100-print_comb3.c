#include <stdio.h>

/**
 * main - Prints all possible different combinations of two digits
 *
 * Return: Always 0 (success)
 */

int main(void)
{
int k = '0';
int l = '0';
while (k <= '8')
{
while (l <= '9')
{
if (!(k > l) || k == l)
{
putchar(k);
putchar(l);
if (k == '8' && l == '9')
{
putchar('\n');
}
else
{
putchar(',');
putchar(' ');
}
}
l++;
}
l = '0';
k++;
}
return (0);
}

