#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t list.
 * @head: Pointer to the head of the doubly linked list.
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
dlistint_t *end = head;
dlistint_t *next;

while (end)
{
next = end->next;
free(end);
end = next;
}
}
