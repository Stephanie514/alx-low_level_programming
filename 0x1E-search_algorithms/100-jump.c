#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers
 * @array: array of integers
 * @size: size of array
 * @value: value to be searched
 *
 * Return: first index of value searched or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
size_t currentIndex, jumpIndex, stepSize;

if (array == NULL || size == 0)
return (-1);

stepSize = sqrt(size);
for (currentIndex = 0, jumpIndex = stepSize;
jumpIndex < size && array[jumpIndex] < value;
currentIndex = jumpIndex, jumpIndex += stepSize)
{
printf("Value checked array[%ld] = [%d]\n", jumpIndex, array[jumpIndex]);
}

printf("Value found between indexes [%ld] and [%ld]\n",
currentIndex, jumpIndex);

jumpIndex = (jumpIndex < size) ? jumpIndex : size - 1;

for (; currentIndex <= jumpIndex; ++currentIndex)
{
printf("Value checked array[%ld] = [%d]\n", currentIndex, array[currentIndex]);

if (array[currentIndex] == value)
{
printf("Found %d at index: %ld\n", value, currentIndex);
return (currentIndex);
}
}

return (-1);
}
