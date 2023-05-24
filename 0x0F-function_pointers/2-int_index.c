#include "function_pointers.h"

/**
 * int_index - a function that searches for an integer
 * @size: is the number of elements in the array
 * @array: array of integers
 * @cmp: is a pointer to the function to be used to compare values
 *
 * Return: returns the index of the first element for
 * which the cmp function does not return 0
 * If no element matches, return -1, if size <= 0, return -1
 */

int int_index(int *array, int size, int (*cmp)(int))
{
int pos;
if (array == NULL || cmp == NULL)
return (-1);
for (pos = 0; pos < size; pos++)
{
if (cmp(array[pos]))
return (pos);
}
return (-1);
}
