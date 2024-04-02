#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 * @list: Pointer to the head of the doubly linked list
 * Return: Pointer to the node that was swapped
 */
listint_t *swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	listint_t *back = node1->prev;
	listint_t *current = node1;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Cocktail shaker sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap_done = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = *list;
	while (swap_done == 1)
	{
		swap_done = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_nodes(node->next, list);
				swap_done = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swap_done == 0)
			break;
		swap_done = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_nodes(node, list);
				swap_done = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}

