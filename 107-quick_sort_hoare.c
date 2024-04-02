#include "sort.h"

void swap_integers(int *a, int *b);
size_t hoare_partition_scheme(int *array, size_t size,
		ssize_t left, ssize_t right);
void hoare_quick_sort(int *array, size_t size, ssize_t left, ssize_t right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_integers - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_integers(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition_scheme - Partition the array using Hoare's scheme.
 * @array: An array of integers.
 * @size: The size of the array.
 * @left: The lowest index of the partition.
 * @right: The highest index of the partition.
 *
 * Return: The partition index.
 */
size_t hoare_partition_scheme(int *array, size_t size,
		ssize_t left, ssize_t right)
{
	int pivot = array[right];
	ssize_t i = left - 1, j = right + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap_integers(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * hoare_quick_sort - Perform the quick sort algorithm recursively.
 * @array: An array of integers.
 * @size: The size of the array.
 * @left: The lowest index of the partition.
 * @right: The highest index of the partition.
 */
void hoare_quick_sort(int *array, size_t size, ssize_t left, ssize_t right)
{
	if (left < right)
	{
		size_t partition = hoare_partition_scheme(array, size, left, right);

		hoare_quick_sort(array, size, left, partition);
		hoare_quick_sort(array, size, partition + 1, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending order using
 * the Quick sort algorithm with Hoare's partition scheme.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_quick_sort(array, size, 0, size - 1);
}
