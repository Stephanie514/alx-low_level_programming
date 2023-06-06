#include "lists.h"

/**
* _al - reassign memory to an array of pointers to
* nodes in listint_t linked list
* @i: old list to add to
* @c: this is the size of the old list
* @crt: what is to be added to the index
*
* Return: pointer to new list
*/

const listint_t **_al(const listint_t **i, size_t c, const listint_t *crt)
{
	const listint_t **currentlist;
	size_t b;

	currentlist = malloc(c * sizeof(listint_t *));
	if (!currentlist)
	{
		free(i);
		exit(98);
	}
	for (b = 0; b < c - 1; b++)

		currentlist[b] = i[b];
	currentlist[b] = crt;
	free(i);
	return (currentlist);
}

/**
* free_listint_safe - function that frees a listint_t list.
*
* @h: pointer to the head of listint_t list
* Return: the number of nodes in the list
*
*/

size_t free_listint_safe(listint_t **h)
{
	size_t b, ttl = 0;
	const listint_t **i = NULL;
	listint_t *next;

	while (*h != NULL)
	{
		for (b = 0; b < ttl; b++)
		{
			if (*h == i[b])
			{
				*h = NULL;
				free(i);
				return (ttl);
			}
		}
		ttl++;
		i = _al(i, ttl, *h);
		next = (*h)->next;
		free(*h);
		*h = next;
	}
	free(i);
	return (ttl);
}
