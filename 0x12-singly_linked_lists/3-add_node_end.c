#include "lists.h"

/**
 * add_node_end - this adds a new node at the end of a list_t list.
 * @head: This is the pointer to the head of the list.
 * @str: This string is to be duplicated and stored in the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	unsigned int len;

	len = 0;
	while (str[len])
		len++;
	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->str = strdup(str);
	new->len = len;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		list_t *end = *head;

		while (end->next != NULL)
		{
			end = end->next;
		}
		end->next = new;
	}
	return (new);
}
