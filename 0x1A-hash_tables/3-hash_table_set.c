#include "hash_tables.h"

/**
 * hash_table_set - This adds an element to the hash table
 * @ht: The pointer to hash table
 * @key: key to add
 * @value: The value associated with the key
 *
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *new_value;
	hash_node_t *current;
	hash_node_t *new_node;

	if (!ht || !key || *key == '\0' || !value)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current)
	{
		if (strcmp(key, current->key) == 0)
		{
			new_value = strdup(value);

			if (!new_value)
				return (0);
			free(current->value);
			current->value = new_value;
			return (1);
		}
		current = current->next;
	}
	new_node = malloc(sizeof(hash_node_t));

	if (!new_node)
		return (0);
	new_value = strdup(value);

	if (!new_value)
	{
		free(new_node);
		return (0);
	}
	new_node->key = strdup(key);
	new_node->value = new_value;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
