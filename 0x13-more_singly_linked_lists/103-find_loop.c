#include "lists.h"

/**
* find_listint_loop - function that finds the loop in a linked list.
* @head: this is the pointer to the start of the list
*
* Return: The address of the node where the loop starts
* or NULL if there is no loop
*/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *val, *dig;

	val = dig = head;

	while (val != NULL && dig != NULL && dig->next)
	{
		val = val->next;
		dig = dig->next->next;
		if (val == dig)
		{
			val = head;
			break;
		}
	}
	if (val == NULL || dig == NULL || !dig->next)
		return (NULL);
	while (val != dig)
	{
		val = val->next;
		dig = dig->next;
	}
	return (dig);
}
