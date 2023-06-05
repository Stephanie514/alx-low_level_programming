#include "lists.h"

/**
 * pop_listint - function which deletes the head node of a linked list
 * @head: pointer to first element in linked list
 *
 *
 * Return: head node’s data (n), or 0 if empty
 */
int pop_listint(listint_t **head)
{
	listint_t *end;
	int ttl;

	if (head == NULL || *head == NULL)
		return (0);
	ttl = (*head)->n;
	end = (*head)->next;
	free(*head);
	*head = end;

	return (ttl);
}
