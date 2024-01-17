#include "search_algos.h"
/**
 * linear_search - searches for a value in an array (linear search)
 * @array: array of integers
 * @size: size of array
 * @value: value that should be found
 *
 * Return: index of value searched or -1 if it doesn't exist
 */
int linear_search(int *array, size_t size, int value)
{
size_t a = 0;

if (array == NULL)
return (-1);
while (a < size)
{
printf("Value checked array[%lu] = [%d]\n", a, array[a]);
if (value == array[a])
{
printf("Found %d at index %lu\n", value, a);
return (a);
}
a++;
}
return (-1);
}
