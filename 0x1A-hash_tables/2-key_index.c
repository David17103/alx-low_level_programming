#include "hash_tables.h"

/**
 * key_index - Calculates the index for a key in a hash table.
 * @key: The key, represented as a string.
 * @size: The size of the hash table array.
 *
 * Return: The index where the key/value pair should be stored in the array.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    return (hash_djb2(key) % size);
}
