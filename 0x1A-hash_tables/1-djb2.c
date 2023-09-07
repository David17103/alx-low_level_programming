/**
 * custom_hash - Custom hash function that transforms a string into a hash value.
 * @str: The input string, which should be a unique value within the hash table.
 *
 * Return: The resulting hash value.
 */
unsigned long int custom_hash(const unsigned char *str)
{
    unsigned long int hash;
    int c;

    hash = 5381;
    while ((c = *str++))
    {
	    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return (hash);
}

