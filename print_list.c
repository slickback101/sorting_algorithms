#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a linked list of integers.
 * @list: Pointer to the head of the linked list.
 */

void print_list(const listint_t *list)
{
    if (list == NULL)
    {
        printf("Empty list\n");
        return;
    }

    while (list != NULL)
    {
        printf("%d", list->n);
        if (list->next != NULL)
            printf(", ");
        list = list->next;
    }
    printf("\n");
}
