#include "lists.h"

/**
* sum_dlistint - Returns the sum of all the data (n) of a dlistint_t linked list.
* @head: Pointer to the first node in the doubly linked list.
*
* Return: The sum of all data, or 0 if the list is empty.
*/
int sum_dlistint(dlistint_t *head)
{
int total = 0;
dlistint_t *current = head;

while (current != NULL)
{
total += current->n;
current = current->next;
}

return total;
}
