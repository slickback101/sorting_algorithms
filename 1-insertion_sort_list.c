#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using insertion sort.
 * @list: Pointer to the head of the unsorted linked list.
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return; /** Check for empty list or single-node list */

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *insertion_point = current->prev;

        while (insertion_point != NULL && insertion_point->n > current->n)
        {
            insertion_point = swap_nodes(insertion_point, list);
            print_list(*list); /** Print the list after each swap */
            insertion_point = insertion_point->prev;
        }

        current = current->next;
    }
}

/**
 * swap_nodes - Swaps a node with its previous node in a doubly linked list.
 * @node: Node to be swapped (current node).
 * @list: Pointer to the head of the linked list.
 * Return: Pointer to the new position of the node after swapping.
 */

listint_t *swap_nodes(listint_t *node, listint_t **list)
{
    listint_t *prev_node = node->prev;
    listint_t *next_node = node->next;

    /**Adjust links for the swapped nodes*/
    if (prev_node != NULL)
        prev_node->next = next_node;
    if (next_node != NULL)
        next_node->prev = prev_node;

    node->prev = prev_node->prev;
    node->next = prev_node;
    prev_node->prev = node;

    if (node->prev == NULL)
        *list = node;

    return node;
}
