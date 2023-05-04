#include "main.h"

/**
 * rev_string - reversed array
 * @n: integer variables
 * Return: 0
 */

void rev_string(char *n)
{
int a = 0;
int b = 0;
char Temp;
while (*(n + a) != '\0')
{
a++;
}
a--;
for (b = 0; b < a; b++, a--)
{
Temp = *(n + b);
*(n + b) = *(n + a);
*(n + a) = Temp;
}
}

/**
 * infinite_add -  a function that adds two numbers.
 * @n1: first number to add
 * @n2: second number to add
 * @r: pointer to storage
 * @size_r: storage size
 * Return: pointer to function
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
int maxed_out = 0, a = 0, b = 0, numbers = 0;
int ttl1 = 0, ttl2 = 0, totalT = 0;
while (*(n1 + a) != '\0')
a++;
while (*(n2 + b) != '\0')
b++;
a--;
b--;
if (b >= size_r || a >= size_r)
return (0);
while (b >= 0 || a >= 0 || maxed_out == 1)
{
if (a < 0)
ttl1 = 0;
else
ttl1 = *(n1 + a) -'0';
if (b < 0)
ttl2 = 0;
else
ttl2 = *(n2 + b) -'0';
totalT = ttl1 + ttl2 + maxed_out;
if (totalT >= 10)
maxed_out = 1;
else
maxed_out = 0;
if (numbers >= (size_r - 1))
return (0);
*(r + numbers) = (totalT % 10) + '0';
numbers++;
b--;
a--;
}
if (numbers == size_r)
return (0);
*(r + numbers) = '\0';
rev_string(r);
return (r);
}
