#include <stdlib.h>
#include "main.h"

/**
* number_string - helper function which counts
* number of words in a string
* @d: the string
*
* Return: number of words
*/

int number_string(char *d)
{
int bn, s, r;
bn = 0;
r = 0;
for (s = 0; d[s] != '\0'; s++)
{
if (d[s] == ' ')
bn = 0;
else if (bn == 0)
{
bn = 1;
r++;
} 
}
return (r);
}

/**
* strtow - function that splits a string into words.
* @str: the string to split
*       
* Return: pointer to array of strings or 0 error 
*/

char **strtow(char *str)
{
char **array, *sh;
int a, b = 0, length = 0, lett, g = 0, beg, fin;
while (*(str + length)) length++;
lett = number_string(str);
if (lett == 0)
return (NULL);
array = (char **) malloc(sizeof(char *) * (lett + 1));
if (array == NULL)
return (NULL);
for (a = 0; a <= length; a++)
{
if (str[a] == ' ' || str[a] == '\0')
{
if (g)
{
fin = a; sh = (char *) malloc(sizeof(char) * (g + 1));
if (sh == NULL)
return (NULL);
while (beg < fin)
*sh++ = str[beg++];
*sh = '\0';
array[b] = sh - g; b++;
g = 0;
}
}
else if (g++ == 0) beg = a;
}
array[b] = NULL;
return (array);
}
