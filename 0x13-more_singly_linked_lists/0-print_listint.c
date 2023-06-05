#include "lists.h"

/**
 * print_listint - is the name of the function.
 *
 * @h: is the parameter of the function.
 * pointer to a constant list_t structure
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t nodenum = 0;
	const listint_t *npointer = h;

	while (npointer)
	{
		printf("%d\n", npointer->n);
		nodenum++;
		npointer = npointer->next;
	}
	return (nodenum);
}
