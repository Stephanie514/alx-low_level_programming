#include <stdlib.h>
#include "main.h"
/**
 * *_realloc - function that reallocates a memory block using malloc and free
 * @ptr: the pointer to memory formally allocated by malloc
 * @old_size: size of allocated memory for p
 * @new_size: new size of the new memory block
 *
 * Return: pointer to the current allocated memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *pointer;
char *prev_pointer;
unsigned int r;
if (old_size == new_size)
return (ptr);
if (new_size == 0 && ptr)
{
free(ptr);
return (NULL);
}
if (!ptr)
return (malloc(new_size));
pointer = malloc(new_size);
if (!pointer)
return (NULL);
prev_pointer = ptr;
if (old_size > new_size)
{
for (r = 0; r < new_size; r++)
pointer[r] = prev_pointer[r];
}
if (old_size < new_size)
{
for (r = 0; r < old_size; r++)
pointer[r] = prev_pointer[r];
}
free(ptr);
return (pointer);
}
