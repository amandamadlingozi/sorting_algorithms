#include "sort.h"
#include "stdio"
/**
 * swap - Swaps the positions of two elements in an array
 * @array: The array
 * @index1: Index of the first element
 * @index2: Index of the second element
 */
void swap(int *array, ssize_t index1, ssize_t index2)
{
	int tmp = array[index1];

	array[index1] = array[index2];
	array[index2] = tmp;
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme for Quick sort
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: The size of the array
 *
 * Return: Index of the pivot
 */
int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1;

	for (ssize_t j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(array, i + 1, high);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: The size of the array
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}

