#include "lists.h"

/**
 * _l - reassign memory to an array of pointers to
 * nodes in listint_t linked list
 * @index: old list to add to
 * @count: this is the size of the old list
 * @current: what is to be added to the index
 *
 * Return: pointer to new list
 */

const listint_t **_l(const listint_t **index, size_t count, const listint_t *current)
{
	const listint_t **currentlist;
	size_t b;

	currentlist = malloc(count * sizeof(listint_t *));

	if (currentlist == NULL)
	{
		free(index);
		exit(98);
	}
	for (b = 0; b < count - 1; b++)

		currentlist[b] = index[b];
	currentlist[b] = current;
	free(index);
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
	const listint_t **index = NULL;

	while (head != NULL)
	{
		for (b = 0; b < ttl; b++)
		{
			if (head == index[b])

			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(index);
				return (ttl);
			}
		}
		ttl++;
		index = _l(index, ttl, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(index);
	return (ttl);
}
