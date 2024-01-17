#include "search_algos.h"

/**
 * jump_search - This searches for a value in sorted array of integers
 * @array: An array of integers
 * @size: The size of array
 * @value: The value at be searched
 *
 * Return: The index of value searched or -1
 */

int jump_search(int *array, size_t size, int value)
{
size_t a, Indexjump, sizeStep;

if (array == NULL || size == 0)
return (-1);

sizeStep = sqrt(size);
for (a = 0, Indexjump = 0; Indexjump < size && array[Indexjump] < value;)
{
printf("Value checked array[%ld] = [%d]\n", Indexjump, array[Indexjump]);
a = Indexjump;
Indexjump += sizeStep;
}

printf("Value between indexes [%ld] and [%ld]\n", a, Indexjump);

Indexjump = (Indexjump < size - 1) ? Indexjump : size - 1;
for (; a < Indexjump && array[a] < value; a++)
printf("Value checked array[%ld] = [%d]\n", a, array[a]);
printf("Value checked array[%ld] = [%d]\n", a, array[a]);

return (array[a] == value ? (int)a : -1);
}
