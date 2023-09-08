#include "hash_tables.h"

/**
 * hash_table_delete - This function frees a hash table and all nodes
 * @ht: Pointer to hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int a;
	hash_node_t *current;
	hash_node_t *next;

	if (!ht)
		return;
	for (a = 0; a < ht->size; a++)
	{
		if (ht->array[a])
		{
			current = ht->array[a];

			while (current)
			{
				next = current->next;
				free(current->key);
				free(current->value);
				free(current);
				current = next;
			}
		}
	}
	free(ht->array);
	free(ht);
}
