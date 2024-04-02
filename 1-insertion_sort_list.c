#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
/* Swap nodes */
			iter->prev = insert->prev;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->next = insert;
			insert->prev = iter;

			if (iter->prev == NULL)
				*list = iter;
			print_list((const listint_t *)*list);

			insert = iter->prev;
		}
	}
}
