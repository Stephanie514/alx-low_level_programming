#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node at
 * index of a listint_t linked list.
 * @head: pointer to 1st element
 * @index: the index of the node that should be deleted.
 * Return: 1 if it succeeded, -1 if it failed.
 */


int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *pres = *head;
	listint_t *prev = NULL;
	unsigned int num = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(pres);
		return (1);
	}
	do {
		prev = pres;
		pres = pres->next;
		num++;

		if (pres == NULL || pres->next == NULL)
			return (-1);
	} while (num < index);
	prev->next = pres->next;
	free(pres);
	return (1);
}
