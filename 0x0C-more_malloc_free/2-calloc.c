#include <stdlib.h>
#include "main.h"

/**
 * *_numbyte - memory with a constant byte
 * @q: the memory to be filled
 * @r: character to copy
 * @g: the number of times to copy b
 *
 * Return: pointer to the memory area q
 */

char *_numbyte(char *q, char r, unsigned int g)
{
unsigned int h;
for (h = 0; h < g; h++)
{
q[h] = r;
}
return (q);
}

/**
 * *_calloc - function that allocates memory for an array, using malloc.
 * @nmemb: the elements in the array
 * @size: the size of each element
 *
 * Return: pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
char *p;
if (nmemb == 0 || size == 0)
return (NULL);
p = malloc(size * nmemb);
if (p == NULL)
return (NULL);
_numbyte(p, 0, nmemb * size);
return (p);
}
