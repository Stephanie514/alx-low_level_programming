#include "lists.h"

/**
 * listint_len - is the name of the function.
 *
 * @h: is the parameter of the function.
 * pointer to a constant listint_t structure
 *
 * Return: the number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t nodenum = 0;
	const listint_t *pointer = h;

	while (pointer)
	{
		pointer = pointer->next;
		nodenum++;
	}
	return (nodenum);
}
