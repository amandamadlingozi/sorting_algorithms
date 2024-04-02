#include "sort.h"
#include <stdlib.h>

/**
 * _calloc - allocate memory for an array and initialize with zeros
 * @nmemb: number of elements
 * @size: size of each element
 * Return: pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		ptr[i] = 0;

	return (ptr);
}

/**
 * merge - merge two sorted subarrays into one sorted array
 * @arr: array containing the subarrays to merge
 * @tmp: temporary array used in merging process
 * @start: starting index of the first subarray
 * @mid: ending index of the first subarray and starting index of the second
 * @end: ending index of the second subarray
 */
void merge(int *arr, int *tmp, int start, int mid, int end)
{
	int size_left = mid - start + 1, size_right = end - mid;
	int *array_left, *array_right;
	int left, right, i = 0;

	array_left = &tmp[0];
	array_right = &tmp[size_right];
	for (left = 0; left < size_left; left++)
		array_left[left] = arr[start + left];
	for (right = 0; right < size_right; right++)
		array_right[right] = arr[mid + 1 + right];
	left = 0, right = 0, i = start;
	while (left < size_left && right < size_right)
	{
		if (array_left[left] <= array_right[right])
			arr[i] = array_left[left], left++;
		else
			arr[i] = array_right[right], right++;
		i++;
	}
	while (left < size_left)
		arr[i] = array_left[left], left++, i++;
	while (right < size_right)
		arr[i] = array_right[right], right++, i++;
}

/**
 * merge_sort_recursive - recursively sort an array using merge sort algorithm
 * @array: array to be sorted
 * @tmp: temporary array used in merging process
 * @start: starting index of the subarray to be sorted
 * @end: ending index of the subarray to be sorted
 */
void merge_sort_recursive(int *array, int *tmp, int start, int end)
{
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		merge_sort_recursive(array, tmp, start, mid);
		merge_sort_recursive(array, tmp, mid + 1, end);
		merge(array, tmp, start, mid, end);
	}
}

/**
 * merge_sort - sort an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;

	tmp = _calloc(size, sizeof(int));
	if (tmp == NULL)
		return;

	merge_sort_recursive(array, tmp, 0, size - 1);
	free(tmp);
}
