#include "lists.h"

/**
* free_listint2 - function that frees a listint_t list.
* @head: Pointer to the listint_t list.
*
* Return : void
*/

void free_listint2(listint_t **head)
{
	listint_t *next;
	listint_t *end = *head;

	if (head == NULL)
		return;
	while (end != NULL)
	{
		next = end->next;
		free(end);
		end = next;
	}
	*head = NULL;
}
