#include "hash_tables.h"

/**
 * hash_table_print - Prints key/value pairs in the order they appear in the hash table.
 * @ht: A pointer to the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
    unsigned long int i, count = 0;
    hash_node_t *node;

    if (ht == NULL)
        return;
    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        if (ht->array[i] != NULL)
        {
            node = ht->array[i];
            while (node != NULL)
            {
                if (count > 0)
                    printf(", ");
                printf("'%s': '%s'", node->key, node->value);
                node = node->next;
                count++;
            }
        }
    }
    printf("}\n");
}

