#include "main.h"
#include <stdlib.h>
/**
* alloc_grid - function that returns a pointer
* to a 2 dimensional array of integers.
* @width: the width input
* @height: the height input
* Return: pointer to a 2 dimensional array
*/
int **alloc_grid(int width, int height)
{
int **a;
int g, h;
if (height <= 0 || width <= 0)
return (NULL);
a = malloc(sizeof(int *) * height);
if (a == NULL)
return (NULL);
for (g = 0; g < height; g++)
{
a[g] = malloc(sizeof(int) * width);
if (a[g] == NULL)
{
for (; g >= 0; g--)
free(a[g]);
free(a);
return (NULL);
}
}
for (g = 0; g < height; g++)
{
for (h = 0; h < width; h++)
a[g][h] = 0;
}
return (a);
}
