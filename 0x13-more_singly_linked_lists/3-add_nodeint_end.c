#include "lists.h"

/**
* add_nodeint_end - this adds a new node at the end of a list_t list.
* @head: This is the pointer to the head of the list.
* @n: This string is to be duplicated and stored in the new node.
*
* Return: Address of the new element, or NULL if it failed.
*/

listint_t *add_nodeint_end(listint_t **head, const int n)
{
        listint_t *newnode;

        newnode = malloc(sizeof(listint_t));
        if (newnode == NULL)
        {
                return (NULL);
        }
        newnode->next = NULL;
        newnode->n = n;
        if (*head == NULL)
        {
                *head = newnode;
		return (newnode);
        }
        else
        {
                listint_t *end = *head;

                while (end->next != NULL)
                {
                        end = end->next;
                }
                end->next = newnode;
        }
        return (newnode);
}
