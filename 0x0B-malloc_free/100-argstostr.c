#include "main.h"
#include <stdlib.h>

/**
* argstostr - function that concatenates all
* the arguments of your program.
* @ac: integer input
* @av: the double pointer array
* Return: NULL
*/

char *argstostr(int ac, char **av)
{
int b, c, d = 0, e = 0;
char *sri;
if (ac == 0 || av == NULL)
return (NULL);
for (b = 0; b < ac; b++)
{
for (c = 0; av[b][c]; c++)
e++;
}
e += ac;
sri = malloc(sizeof(char) * e + 1);
if (sri == NULL)
return (NULL);
for (b = 0; b < ac; b++)
{
for (c = 0; av[b][c]; c++)
{
sri[d] = av[b][c];
d++;
}
if (sri[d] == '\0')
{
sri[d++] = '\n';
}
} return (sri);
}
