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
	const listint_t *pointer = h;

	while (pointer)
	{
		printf("%u\n", pointer->n);
		pointer = pointer->next;
		nodenum++;
	}
	return (nodenum);
}
