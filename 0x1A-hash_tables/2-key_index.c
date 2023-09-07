#include "hash_tables.h"

/**
 * custom_key_index - Calculates the index for a key in a hash table.
 * @key: The key, represented as a string.
 * @size: The size of the hash table array.
 *
 * Return: The index where the key/value pair should be stored in the array.
 */
unsigned long int custom_key_index(const unsigned char *key, unsigned long int size)
{
    return (custom_hash(key) % size);
}
