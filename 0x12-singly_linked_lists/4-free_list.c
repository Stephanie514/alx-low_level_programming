#include "lists.h"

/**
 * free_list - function that frees a list_t list.
 * @head: Pointer to the head of the list.
 *
 * Return : void
 */
void free_list(list_t *head)
{
	list_t *end = head;
	list_t *next;

	while (end)
	{
		next = end->next;
		free(end->str);
		free(end);
		end = next;
	}
}
