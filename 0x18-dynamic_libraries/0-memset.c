#include "main.h"
/**
 * _memset - fills memory with constant byte
 * @s: the area looked at
 * @b: the byte that is filling memory
 * @n: the amount of memory that is being filled
 * Return: new memory
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *p = s;

	while (n--)
	{
		*p++ = b;
	}
	return (s);
}
