#include <stdio.h>
#include "lists.h"

/**
 * print_list - is the name of the function.
 *
 * @h: is the parameter of the function.pointer to a constant list_t structure
 * Return: the number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t num = 0;
	const list_t *newPointer = h;

	while (newPointer)
	{
		if (!newPointer->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", newPointer->len, newPointer->str);
		newPointer = newPointer->next;
		num++;
	}
	return (num);
}

