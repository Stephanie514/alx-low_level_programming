#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
* num_test - checks if a digit is present in string
* @stri: array string
*
* Return: Always 0 (Success)
*/

int num_test(char *stri)
{
unsigned int tally;
tally = 0;
while (tally < strlen(stri))
{
if (!isdigit(stri[tally]))
{
return (0);
}
tally++;
}
return (1);
}

/**
* main - prints program's name
* @argc: number of arguments
* @argv: Arguments
*
* Return: Always 0 (Success)
*/
int main(int argc, char *argv[])
{
int tally;
int strint;
int sum = 0;
tally = 1;
while (tally < argc)
{
if (num_test(argv[tally]))
{
strint = atoi(argv[tally]);
sum += strint;
}
else
{
printf("Error\n");
return (1);
}
tally++;
}
printf("%d\n", sum);
return (0);
}
