#include "sort.h"

/**
 * swap_nodes_list - Swap two nodes in a doubly linked list
 *
 * @head: head of the doubly linked list
 * @n1: first node to swap
 * @n2: second node to swap
 *
 * Return: void
 */
void swap_nodes_list(listint_t **head, listint_t **n1, listint_t **n2)
{

(*n1)->next = (*n2)->next;
if ((*n2)->next)
(*n2)->next->prev = (*n1);

(*n2)->prev = (*n1)->prev;
(*n2)->next = (*n1);

if ((*n1)->prev)
(*n1)->prev->next = (*n2);
else
(*head) = (*n2);

(*n1)->prev = (*n2);
(*n1) = (*n2)->prev;
}

/**
 * insertion_sort_list - sorts a list ascendingly using insertion sort
 *
 * @list: the list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
listint_t *node_to_swap = NULL, *curr = NULL, *next = NULL;

if (!list || !(*list) || !(*list)->next)
return;

curr = (*list)->next;
while (curr)
{
next = curr->next;
node_to_swap = curr->prev;
while (node_to_swap && curr->n < node_to_swap->n)
{
swap_nodes_list(list, &node_to_swap, &curr);
print_list((const listint_t *)*list);
}
curr = next;
}
}
