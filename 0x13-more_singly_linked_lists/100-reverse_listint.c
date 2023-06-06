#include "lists.h"


/**
* reverse_listint - function that reverses a listint_t linked list.
*
* @head: pointer to the 1st node of list
*
* Return: pointer to the first node of the reversed list
*/

listint_t *reverse_listint(listint_t **head)
{
	listint_t *precede = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = precede;
		precede = *head;
		*head = next;
	}
	*head = precede;
	return (*head);
}
