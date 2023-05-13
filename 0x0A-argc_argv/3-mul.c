#include <stdio.h>
#include "main.h"

/**
* _atoi - converts a string to an integer
* @s: string to be converted
*
* Return: the int converted from the string
*/

int _atoi(char *s)
{
int a, b, c, length, z, dig;
a = 0;
b = 0;
c = 0;
length = 0;
z = 0;
dig = 0;
while (s[length] != '\0')
length++;
while (a < length && z == 0)
{
if (s[a] == '-')
++b;
if (s[a] >= '0' && s[a] <= '9')
{
dig = s[a] - '0';
if (b % 2)
dig = -dig;
c = c * 10 + dig;
z = 1;
if (s[a + 1] < '0' || s[a + 1] > '9')
break;
z = 0;
}
a++;
}
if (z == 0)
return (0);
return (c);
}
/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Success), 1 (Error)
 */
int main(int argc, char *argv[])
{
int result, num1, num2;
if (argc < 3 || argc > 3)
{
printf("Error\n");
return (1);
}
num1 = _atoi(argv[1]);
num2 = _atoi(argv[2]);
result = num1 *num2;
printf("%d\n", result);
return (0);
}
