#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* main - Entry point
* Return: Always 0
*/
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);
	ListNode_t *list;
	list = create_listint(array, n);
	if (list == NULL)
	{
		fprintf(stderr, "Failed to create list\n");
		return (EXIT_FAILURE);
	}
	printf("Original list: ");
	print_linked_list(list);
	printf("\n");
	
	insertion_sort(&list);
	
	printf("Sorted list: ");
	print_linked_list(list);
	printf("\n");
	return (EXIT_SUCCESS);
}
