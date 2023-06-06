#include "lists.h"
/**
* insert_nodeint_at_index - function that inserts a
* new node at a given position.
* @head: pointer to the first node
* @idx: the index of the list where the new node should be added
* @n: what to insert in the new node
*
* Return: address of the new node, or NULL if it failed
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int a = 0;
	listint_t *newnode;
	listint_t *hold = *head;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL || head == NULL)
		return (NULL);
	newnode->n = n;
	newnode->next = NULL;
	if (idx == 0)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}
	while (hold && a < idx)
	{
		if (a + 1 == idx)
		{
			newnode->next = hold->next;
			hold->next = newnode;
			return (newnode);
		}
		hold = hold->next;
		a++;
	}
	return (NULL);
}
