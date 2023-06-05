#include "lists.h"
/**
 *
 *
 *
 *
 */
int pop_listint(listint_t **head)
{
	listint_t *end;
	int ttl;
	if (head == NULL || *head == NULL)
		return(0);
	ttl = (*head)->n;
	end = (*head)->next;
	free(*head);
	*head = end;

	return(ttl);
}
