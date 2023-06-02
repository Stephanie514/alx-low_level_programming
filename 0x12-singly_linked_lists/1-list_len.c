#include "lists.h"

/**
 * list_len - is the name of the function.
 *
 * @h: is the parameter of the function.pointer to a constant list_t structure
 * Return: the number of nodes
 */

size_t list_len(const list_t *h)
{
	size_t num = 0;
	const list_t *newPointer = h;

	while (newPointer)
	{
		newPointer = newPointer->next;
		num++;
	}
	return (num);
}
