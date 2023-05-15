#include "main.h"
#include <stdlib.h>

/**
 * create_array - function that creates an array of chars
 * and initializes it with a specific char.
 * @c: character to sign
 *
 * @size: size of array
 * Return: a pointer to the array, or NULL if it fails
 */

char *create_array(unsigned int size, char c)
{
unsigned int g;
char *stri;

stri = malloc(sizeof(char) * size);
if (stri == NULL || size == 0)
return (NULL);
for (g = 0; g < size; g++)
stri[g] = c;
return (stri);
}
