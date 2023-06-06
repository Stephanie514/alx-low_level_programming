#include "lists.h"

/**
 * get_nodeint_at_index - function that returns the nth node
 *                        of a listint_t linked list.
 * @head: the first node in the linked list
 *
 * @index: The index of node to be returned
 *
 * Return: if the node does not exist, return NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int a = 0;
	listint_t *end = head;

	while (end != NULL && a < index)
	{
		end = end->next;
	a++;
	}
	if (end)
	{
		return (end);
	}
	else
	{
		return (NULL);
}
}
