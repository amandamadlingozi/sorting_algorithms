#include "sort.h"

/**
 * custom_swap - swaps two elements in an array
 * @array: array
 * @idx1: index of the first element
 * @idx2: index of the second element
 */
void custom_swap(int *array, int idx1, int idx2)
{
	int temp = array[idx1];

	array[idx1] = array[idx2];
	array[idx2] = temp;
}

/**
 * custom_shell_sort - sorts an array of integers
 * using Shell sort with Knuth sequence
 * @array: array to sort
 * @size: size of the array
 */
void custom_shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;

	if (array == NULL || size < 2)
		return;

/* Calculate initial gap using Knuth sequence */
	while (gap < size / 3)
		gap = 3 * gap + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
/* Perform insertion sort within the gap */
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
				custom_swap(array, j, j - gap);
		}
		print_array(array, size); /* Print array after each iteration */
gap /= 3; /* Reduce gap */
}
}

