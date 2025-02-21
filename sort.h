#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node structure
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	    int n;
	        struct listint_s *prev;
		    struct listint_s *next;
} listint_t;


void print_list(const listint_t *list);
listint_t *create_listint(const int *array, size_t size);
void insertion_sort_list(listint_t **list);

#endif
