#include "lists.h"

/**
 * free_listint - function that frees a listint_t list.
 * @head: Pointer to the head of the list.
 *
 * Return : void
 */

void free_listint(listint_t *head)
{
	listint_t *end = head;
	listint_t *next;
	
	while (end)
	{
		next = end->next;
		free(end);
		end = next;
	}
}
