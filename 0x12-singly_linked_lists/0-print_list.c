#include <stdlib.h>
#include "lists.h"

/**
 * print_list - is the name of the function.
 * size_t - return type of the function.
 *
 * print_list - is the name of the function.
 * @h: is the parameter of the function.pointer to a constant list_t structure
 * Return: it returns the number of elements printed
 */
size_t print_list(const list_t *h)
{
	size_t num = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u]%s\n", h->len, h->str);
		h = h->next;
		num++;
	}
	return (num);
}
