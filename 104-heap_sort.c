#include "sort.h"
#include <stdio.h>

/**
 * swap - utility function to swap two integers
 * @a: integer a
 * @b: integer b
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Heapify a subtree rooted with node i which is
 * an index in arr[]. n is size of heap
 * @array: array
 * @size: size of the array
 * @index: index
 * @n: size of the heap
 */
void heapify(int *array, size_t size, int index, size_t n)
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < (int)n && array[left] > array[largest])
		largest = left;

	if (right < (int)n && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		swap(&array[index], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest, n);
	}
}

/**
 * heap_sort - function that sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int i;
Build heap(rearrange array)
for (i = (size / 2) - 1; i >= 0; i--)
heapify(array, size, i, size);

/* One by one extract an element from heap */
for (i = size - 1; i > 0; i--)
{
	/* Move current root to end */
	swap(&array[0], &array[i]);
	print_array(array, size);

	/* call max heapify on the reduced heap */
	heapify(array, size, 0, i);
}
}
