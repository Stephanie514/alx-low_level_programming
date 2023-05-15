#include "main.h"
#include <stdlib.h>

/**
 * str_concat -  function that concatenates two strings
 * @s1: string one to concanate
 * @s2: string to concanate
 *
 * Return: NULL on failure
 */

char *str_concat(char *s1, char *s2)
{
int g, z;
char *conc;
if (s2 == NULL)
s2 = "";
if (s1 == NULL)
s1 = "";
g = z = 0;
while (s1[g] != '\0')
g++;
while (s2[z] != '\0')
z++;
conc = malloc(sizeof(char) * (g + z + 1));
if (conc == NULL)
return (NULL);
g = z = 0;
while (s1[g] != '\0')
{
conc[g] = s1[g];
g++;
}
while (s2[z] != '\0')
{
conc[g] = s2[z];
g++, z++;
}
conc[g] = '\0';
return (conc);
}
