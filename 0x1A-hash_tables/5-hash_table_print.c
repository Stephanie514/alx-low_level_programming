#include "hash_tables.h"

/**
 * hash_table_print - Function that Print the key:value
 * pairs in a hash table
 * @ht: Pointer to the hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	int first_pair = 1;
	unsigned long int i;

	if (!ht)
		return;
	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i])
		{
			hash_node_t *current = ht->array[i];

			do {
				if (!first_pair)
					printf(", ");
				printf("'%s': '%s'", current->key, current->value);
				first_pair = 0;
				current = current->next;
			} while (current);
		}
	}
	printf("}\n");
}
