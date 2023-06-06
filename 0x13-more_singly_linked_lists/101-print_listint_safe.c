#include "lists.h"

/**
 * _l - reassign memory to an array of pointers to
 * nodes in listint_t linked list
 * @i: old list to add to
 * @c: this is the size of the old list
 * @crt: what is to be added to the index
 *
 * Return: pointer to new list
 */

const listint_t **_l(const listint_t **i, size_t c, const listint_t *crt)
{
	const listint_t **currentlist;
	size_t b;

	currentlist = malloc(c * sizeof(listint_t *));

	if (currentlist == NULL)
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
 * print_listint_safe - function that prints a listint_t linked list.
 *
 * @head: pointer to the head of listint_t list
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t b, ttl = 0;
	const listint_t **i = NULL;

	while (head != NULL)
	{
		for (b = 0; b < ttl; b++)
		{
			if (head == i[b])

			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(i);
				return (ttl);
			}
		}
		ttl++;
		i = _l(i, ttl, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(i);
	return (ttl);
}
