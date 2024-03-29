#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a linked dlistint_t list.
 * @h: A pointer to the head of the doubly linked list.
 * Return: The number of nodes in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
size_t nodenum = 0;
const dlistint_t *pointer = h;

while (pointer)
{
pointer = pointer->next;
nodenum++;
}
return (nodenum);
}
