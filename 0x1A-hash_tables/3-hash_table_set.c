#include "hash_tables.h"

/**
 * create_node - Creates a new key-value pair node for the hash table.
 * @key: The key, a non-empty string.
 * @value: The associated value, which can be an empty string.
 *
 * Return: A pointer to the newly created node, or NULL if memory allocation fails.
 */
hash_node_t *create_node(const char *key, const char *value)
{
    hash_node_t *node = malloc(sizeof(hash_node_t));

    if (node == NULL)
        return (NULL);
    node->key = malloc(strlen(key) + 1);
    if (node->key == NULL)
        return (NULL);
    node->value = malloc(strlen(value) + 1);
    if (node->value == NULL)
        return (NULL);
    strcpy(node->key, key);
    strcpy(node->value, value);
    return (node);
}

/**
 * insert_pair - Inserts a key-value pair into the hash table array (no collision handling).
 * @ht: A pointer to the hash table.
 * @key: The key, a non-empty string.
 * @value: The associated value, which can be an empty string.
 * @index: The index where the key should be stored in the array.
 *
 * Return: 1 on success, 0 on failure.
 */
int insert_pair(hash_table_t *ht, const char *key,
                const char *value, unsigned long int index)
{
    hash_node_t *node = create_node(key, value);

    if (node == NULL)
        return (0);
    node->next = NULL;
    ht->array[index] = node;
    return (1);
}

/**
 * hash_table_set - Adds or updates a key-value pair in the hash table.
 * @ht: A pointer to the hash table.
 * @key: The key, a non-empty string.
 * @value: The associated value, which can be an empty string.
 *
 * Return: 1 on success, 0 on error.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *node;

    if (key == NULL || ht == NULL)
        return (0);
    index = key_index((unsigned char *)key, ht->size);
    node = ht->array[index];
    if (node == NULL)
        return (insert_pair(ht, key, value, index));
    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
        {
            if (strcmp(node->value, value) == 0)
                return (1);
            free(node->value);
            node->value = malloc(strlen(value) + 1);
            if (node->value == NULL)
                return (0);
            strcpy(node->value, value);
            return (1);
        }
        node = node->next;
    }
    if (node == NULL)
    {
        node = create_node(key, value);
        if (node == NULL)
            return (0);
        node->next = ht->array[index];
        ht->array[index] = node;
        return (1);
    }
    return (0);
}

