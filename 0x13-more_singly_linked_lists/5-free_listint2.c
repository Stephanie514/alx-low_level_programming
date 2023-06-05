#include "lists.h"

/**
* free_listint2 - function that frees a listint_t list.
* @head: Pointer to the listint_t list.
*
* Return : void
*/

void free_listint2(listint_t **head)
{
	listint_t *hold;
	listint_t *end = *head;

	if (head == NULL)
		return;
	while (end)
	{
		hold = end->next;
		free(end);
		end = hold;
	}
	*head = NULL;
}
