#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: Pointer to the first node in the doubly linked list.
 * @index: The index of the node to be returned.
 *
 * Return: Pointer to the nth node, or NULL if the node does not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
unsigned int count = 0;
dlistint_t *current = head;

while (current != NULL && count < index)
{
current = current->next;
count++;
}
return (current);
}
