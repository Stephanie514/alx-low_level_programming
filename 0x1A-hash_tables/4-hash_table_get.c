#include "hash_tables.h"

/**
 * hash_table_get - This retrieves the value associated with
 * a key in the hash table
 * @ht: Pointer to hash table
 * @key: key to look up
 *
 * Return: The value associated with the given key, or NULL if key not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current;

	if (!ht || !key || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	for (current = ht->array[index]; current != NULL; current = current->next)
	{
		if (strcmp(key, current->key) == 0)
		{
			return (current->value);
		}
	}
	return (NULL);
}
