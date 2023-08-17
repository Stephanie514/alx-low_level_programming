#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at
 * index of a dlistint_t linked list.
 * @head: Pointer to the pointer to the first element
 * in the doubly linked list.
 * @index: The index of the node that should be deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *current = *head;
unsigned int num = 0;

if (*head == NULL)
return (-1);

if (index == 0)
{
*head = (*head)->next;
if (*head)
(*head)->prev = NULL;
free(current);
return (1);
}

while (current && num < index)
{
current = current->next;
num++;

if (current == NULL)
return (-1);
}

if (current->prev)
current->prev->next = current->next;
if (current->next)
current->next->prev = current->prev;
free(current);
return (1);
}
