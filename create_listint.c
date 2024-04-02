#include "sort.h"
#include <stdlib.h>

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list = NULL;
	listint_t *node = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		/* Allocate memory for new node */
		node = malloc(sizeof(*node));
		if (node == NULL)
		{
			/* Free previously allocated nodes on failure */
			while (list != NULL)
			{
				listint_t *temp = list;
				list = list->next;
				free(temp);
			}
			return NULL;
		}

		/* Assign value from array to node */
		node->n = array[i];

		/* Connect node to the list */
		node->next = list;
		node->prev = NULL;
		if (list != NULL)
			list->prev = node;

		/* Update list pointer to point to the new node */
		list = node;
	}

	return list;
}

