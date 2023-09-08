#include "hash_tables.h"

/**
 * create_hash_table - Initializes and allocates memory for a new hash table.
 * @size: The desired size of the new hash table.
 *
 * Return: A pointer to the newly created hash table, or NULL if allocation fails.
 */

hash_table_t *create_hash_table(unsigned long int size)
{
    unsigned int i = 0;
    hash_table_t *ht = malloc(sizeof(hash_table_t));

    if (ht == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return (NULL);
    }

    ht->size = size;
    ht->array = malloc(sizeof(hash_node_t *) * size);
    if (ht->array == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return (NULL);
    }

    for (; i < size; i++)
        ht->array[i] = NULL;

    return (ht);
}

