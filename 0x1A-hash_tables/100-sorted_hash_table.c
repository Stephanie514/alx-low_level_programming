#include "hash_tables.h"

/**
 * insert_sorted - This function inserts new node to linked list
 * @ht: pointer to sorted hash table
 * @new_node: node to insert
 */
void insert_sorted(shash_table_t *ht, shash_node_t *new_node)
{
shash_node_t *current = ht->shead;

if (current == NULL)
{
ht->shead = ht->stail = new_node;
new_node->snext = new_node->sprev = NULL;
return;
}

while (current)
{
if (strcmp(new_node->key, current->key) < 0)
{
new_node->snext = current;
new_node->sprev = current->sprev;

if (!current->sprev)
ht->shead = new_node;
else
current->sprev->snext = new_node;

current->sprev = new_node;
return;
}
current = current->snext;
}

new_node->sprev = ht->stail;
new_node->snext = ht->stail->snext;
ht->stail->snext = new_node;
ht->stail = new_node;
}

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of hash table
 *
 * Return: pointer to hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *table;

if (size == 0)
return (NULL);

table = calloc(1, sizeof(shash_table_t));
if (table == NULL)
return (NULL);

table->size = size;
table->array = calloc(size, sizeof(shash_node_t *));
if (table->array == NULL)
{
free(table);
return (NULL);
}

return (table);
}

/**
 * shash_table_set - function that adds element to sorted hash table
 * @ht: pointer to hash table
 * @key: key to add to element
 * @value: value to add the element
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
unsigned long int index = 0;
shash_node_t *bucket, *new_node;

if (!ht || !key || !*key || !value)
return (0);

index = key_index((const unsigned char *)key, ht->size);
bucket = ht->array[index];

while (bucket)
{
if (!strcmp(key, bucket->key))
{
free(bucket->value);
bucket->value = strdup(value);
return (bucket->value ? 1 : 0);
}
bucket = bucket->next;
}

new_node = calloc(1, sizeof(shash_node_t));
if (new_node == NULL)
return (0);

new_node->key = strdup(key);
new_node->value = strdup(value);
if (!new_node->key || !new_node->value)
{
free(new_node->key);
free(new_node->value);
free(new_node);
return (0);
}

new_node->next = ht->array[index];
ht->array[index] = new_node;
insert_sorted(ht, new_node);
return (1);
}

/**
 * shash_table_get - retrieves value associated with key
 * @ht: pointer to hash table
 * @key: The key which retrieves value
 *
 * Return: The value or NULL if key does not exist.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
unsigned long int index = 0;
shash_node_t *bucket;

if (!ht || !key || !*key)
return (NULL);

index = key_index((const unsigned char *)key, ht->size);
bucket = ht->array[index];

while (bucket)
{
if (!strcmp(key, bucket->key))
return (bucket->value);
bucket = bucket->next;
}

return (NULL);
}

/**
 * shash_table_print - prints the key:value from ht
 * @ht: pointer to hash table
 */
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *bucket = ht->shead;

int not_fin = 0;

if (!ht)
return;

printf("{");
while (bucket)
{
if (not_fin)
printf(", ");
printf("'%s': '%s'", bucket->key, bucket->value);
not_fin = 1;
bucket = bucket->snext;
}
printf("}\n");
}

/**
 * shash_table_print_rev - prints the key:value from ht in reverse
 * @ht: pointer to hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *bucket = ht->stail;

int not_fin = 0;

if (!ht)
return;

printf("{");
while (bucket)
{
if (not_fin)
printf(", ");
printf("'%s': '%s'", bucket->key, bucket->value);
not_fin = 1;
bucket = bucket->sprev;
}
printf("}\n");
}

/**
 * shash_table_delete - function that frees hash table and all nodes
 * @ht: pointer to hash table
 */
void shash_table_delete(shash_table_t *ht)
{
shash_node_t *bucket, *aux_free;
unsigned long int i = 0;

if (!ht)
return;

for (i = 0; i < ht->size; i++)
{
bucket = ht->array[i];
while (bucket)
{
aux_free = bucket;
bucket = bucket->next;
free(aux_free->key);
free(aux_free->value);
free(aux_free);
}
}

free(ht->array);
free(ht);
}

