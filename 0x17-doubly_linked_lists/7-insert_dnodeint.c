#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    if (h == NULL)
        return NULL;

    dlistint_t *new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (idx == 0)
    {
        new_node->next = *h;
        if (*h != NULL)
            (*h)->prev = new_node;
        *h = new_node;
    }
    else
    {
        dlistint_t *current = *h;
        unsigned int count = 0;

        while (current != NULL && count < idx - 1)
        {
            current = current->next;
            count++;
        }

        if (current == NULL || current->next == NULL)
        {
            free(new_node);
            return NULL;
        }

        new_node->next = current->next;
        new_node->prev = current;
        current->next->prev = new_node;
        current->next = new_node;
    }

    return new_node;
}

