#include "lists.h"

/**
 * print_dlistint - Prints all the elements of a dlistint_t list.
 * @h: A pointer to the head of the doubly linked list.
 * Return: The number of nodes in the list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t nodenum = 0;
	const dlistint_t *npointer = h;

	while (npointer)
	{
		printf("%d\n", npointer->n);
		nodenum++;
		npointer = npointer->next;
	}

	return (nodenum);
}
