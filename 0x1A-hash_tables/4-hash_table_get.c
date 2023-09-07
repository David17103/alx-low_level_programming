#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value associated with a key in the hash table.
 * @ht: A pointer to the hash table array.
 * @key: The key, a non-empty string.
 *
 * Return: The value associated with the key, or NULL if the key cannot be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *node;

    if (ht == NULL)
        return (NULL);
    if (key == NULL)
        return (NULL);
    index = key_index((unsigned char *)key, ht->size);
    if (ht->array[index] == NULL)
        return (NULL);
    if (strcmp(ht->array[index]->key, key) == 0)
        return (ht->array[index]->value);
    node = ht->array[index];
    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
            return (node->value);
        node = node->next;
    }
    return (NULL);
}
