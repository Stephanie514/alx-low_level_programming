#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - function that returns a pointer to a newly
 * allocated space in memory which contains a
 * copy of the string given as a parameter.
 *
 * @str: char
 *
 * Return: 0
 */

char *_strdup(char *str)
{
char *bbb;
int y, z = 0;

if (str == NULL)
return (NULL);
y = 0;
while (str[y] != '\0')
y++;
bbb = malloc(sizeof(char) * (y + 1));
if (bbb == NULL)
return (NULL);
for (z = 0; str[z]; z++)
bbb[z] = str[z];
return (bbb);
}
