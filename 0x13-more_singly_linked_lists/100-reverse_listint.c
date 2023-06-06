#include "lists.h"
#include <stdio.h>

/**
* reverse_listint - function that reverses a listint_t linked list.
*
* @head: pointer to the 1st node of list
*
* Return: pointer to the first node of the reversed list
*/

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *pres = *head;

while (pres)
{
	listint_t *next = pres->next;

	pres->next = prev;
	prev = pres;
	pres = next;
}

*head = prev;
return (*head);
}
