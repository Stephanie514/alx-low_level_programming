#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * in a dlistint_t list.
 * @h: Pointer to the pointer to the first node in the doubly linked list.
 * @idx: The index at which the new node should be inserted.
 * @n: The value to insert in the new node.
 *
 * Return: Address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int a = 0;
	dlistint_t *newnode;
	dlistint_t *hold = *h;

	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL || h == NULL)
		return (NULL);
	newnode->n = n;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (idx == 0)
	{
		newnode->next = *h;
		if (*h)
			(*h)->prev = newnode;
		*h = newnode;
		return (newnode);
	}

	while (hold && a < idx)
	{
		if (a + 1 == idx)
		{
			newnode->next = hold->next;
			newnode->prev = hold;
			if (hold->next)
				hold->next->prev = newnode;
			hold->next = newnode;
			return (newnode);
		}
		hold = hold->next;
		a++;
	}
	free(newnode);
	return (NULL);
}
