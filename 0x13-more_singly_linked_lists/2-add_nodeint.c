#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a list_t list.
 * @head: Pointer to the head of the list.
 * @n: what is to be added to the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newnode;

	newnode = malloc(sizeof(listint_t));

	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->next = *head;
	newnode->n = n;
	*head = newnode;

	return (*head);
}
