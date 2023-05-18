#include <stdlib.h>
#include "main.h"
/**
 * *array_range - a function that creates an array of integers.
 * @min: minimum values stored
 * @max: maximum values stored and the elements
 *
 * Return: pointer to the new array
 */

int *array_range(int min, int max)
{
int *p;
int a, contain;
if (min > max)
return (NULL);
contain = max - min + 1;
p = malloc(sizeof(int) * contain);
if (p == NULL)
return (NULL);
for (a = 0; min <= max; a++)
p[a] = min++;
return (p);
}

