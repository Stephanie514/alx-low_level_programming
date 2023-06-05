#include "lists.h"

/**
* free_listint2 - function that frees a listint_t list.
* @head: Pointer to the listint_t list.
*
* Return : void
*/

void free_listint2(listint_t **head)
{
	listint_t *end;

	if (head == NULL)
		return;
	while (*head)
	{
		end = (*head)->next;
		free(*head);
		*head = end;
	}
	*head = NULL;
}
