#include "hash_tables.h"

/**
 * key_index - Compute the index for a given key.
 * @key: The key to be hashed.
 * @size: The size of the hash table.
 *
 * Return: The index where the 'key' should be stored in the hash table,
 *         calculated using the djb2 hash algorithm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
