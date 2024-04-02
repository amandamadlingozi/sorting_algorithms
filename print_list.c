#include "sort.h"
#include <stdio.h>

/**
 * print_linked_list - Prints a doubly linked list of integers
 * @list: Pointer to the head of the list
 */
void print_list(const listint_t *list)
{
	const listint_t *current = list;

	while (current != NULL)
	{
		printf("%d", current->n);
		current = current->next;
		if (current != NULL)
			printf(", ");
		printf("\n");
	}
