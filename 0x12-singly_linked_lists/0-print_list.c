#include <stdio.h>
#include "lists.h"

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */

size_t print_list(const list_t *h)
{
	size_t num;
	num = 0;
	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("%s\n", h->str);
		}
		h = h->next;
		num++;
	}
	return (num);
}
