#include "lists.h"

/**
 * sum_listint - function that returns the sum of all the
 * data (n) of a listint_t linked list
 *
 * @head: the first node
 * Return: sum and 0 if list is empty
 */

int sum_listint(listint_t *head)
{
	int total = 0;
	listint_t *end = head;

	while (end != NULL)
	{
		total = total + end->n;
		end = end->next;
	}
	return (total);
}


