#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 *
 * Return: the number of nodes
 */
size_t print_list(cont list_t *h);
{
	size_t = 0;

	while (h)
	{ 
	if (!h->str)
	printf("[0] (nil)\n");
	else
	printf("[%u] %s\n",h->len, h->str);
	}
return (s)
}

