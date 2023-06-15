#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    if (head == NULL || *head == NULL)
        return -1;

    dlistint_t *current = *head;
    unsigned int count = 0;

    if (index == 0)
    {
        *head = current->next;
        if (current->next != NULL)
            current->next->prev = NULL;
        free(current);
        return 1;
    }

    while (current != NULL && count < index)
    {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return -1;

    if (current->next == NULL)
    {
        current->prev->next = NULL;
        free(current);
        return 1;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    return 1;
}
