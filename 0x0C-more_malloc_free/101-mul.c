#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#define ERR_MSG "Error"

/**
 * arg_check - if a string contains a non-digit character
 * @d: string to be evaluated
 *
 * Return: 0 if a non-digit present, 1 if not
 */
int arg_check(char *d)
{
int b = 0;
while (d[b])
{
if (d[b] < '0' || d[b] > '9')
return (0);
b++;
}
return (1);
}

/**
 * stringL - this returns length of a string
 * @l: the string to evaluate
 *
 * Return: length of the string
 */
int stringL(char *l)
{
int v = 0;
while (l[v] != '\0')
{
v++;
}
return (v);
}

/**
 * err - errors for main are managed
 */
void err(void)
{
printf("Error\n");
exit(98);
}

/**
 * main - program that multiplies two positive numbers.
 * @argc: the number of arguments
 * @argv: the array of arguments
 *
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
char *c1, *c2;
int length1, length2, length, m, transf, num1, num2, *val, t = 0;
c1 = argv[1], c2 = argv[2];
if (argc != 3 || !arg_check(c1) || !arg_check(c2))
err();
length1 = stringL(c1);
length2 = stringL(c2);
length = length1 + length2 + 1;
val = malloc(sizeof(int) * length);
if (!val)
return (1);
for (m = 0; m <= length1 + length2; m++)
val[m] = 0;
for (length1 = length1 - 1; length1 >= 0; length1--)
{
num1 = c1[length1] - '0';
transf = 0;
for (length2 = stringL(c2) - 1; length2 >= 0; length2--)
{
num2 = c2[length2] - '0';
transf += val[length1 + length2 + 1] + (num1 *num2);
val[length1 + length2 + 1] = transf % 10;
transf /= 10;
}
if (transf > 0)
val[length1 + length2 + 1] += transf;
}
for (m = 0; m < length - 1; m++)
{
if (val[m])
t = 1;
if (t)
_putchar(val[m] + '0');
}
if (!t)
_putchar('0');
_putchar('\n');
free(val);
return (0);
}
