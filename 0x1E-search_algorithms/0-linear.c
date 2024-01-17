#include "search_algos.h"
/**
 * linear_search - this searches for a value in an array (linear search)
 * @array: an array of integers
 * @size: the size of array
 * @value: value that should be found
 *
 * Return: the index of value searched or -1 if it doesn't exist
 */
int linear_search(int *array, size_t size, int value)
{
size_t a;
if (array == NULL)
return (-1);
for (a = 0; a < size; a++)
{
printf("Value checked array[%lu] = [%d]\n", a, array[a]);
if (value == array[a])
{
printf("Found %d at index %lu\n", value, a);
return (a);
}
}
return (-1);
}
