#include "search_algos.h"
/**
 * binary_search - Searches for a value in a sorted array
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, return the index of the item.
 *
 * Description: Print sub Array.
 */
int binary_search(int *array, size_t size, int value)
{
size_t low, high, mid, a;

if (array == NULL)
return (-1);
low = 0;
high = size - 1;
while (high >= low)
{
printf("Searching in array: ");
for (a = low; a < high; a++)
printf("%d, ", array[a]);
printf("%d\n", array[a]);
mid = low + (high - low) / 2;
if (array[mid] == value)
return (mid);
if (array[mid] > value)
high = mid - 1;
else
low = mid + 1;
}
return (-1);
}
