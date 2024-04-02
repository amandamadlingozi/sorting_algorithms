#include "sort.h"
#include <stdlib.h>

/**
 *  _calloc - allocate memory for an array and initialize it with zeros
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
 * counting_sort - sort an array of integers using counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max_value = 0;
	int *counter = NULL, *sorted_array = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Find maximum value in the array */
	for (i = 0; i < size; i++)
		if (array[i] > max_value)
			max_value = array[i];

	/* Allocate memory for counter array and sorted array */
	counter = _calloc(max_value + 1, sizeof(int));
	sorted_array = _calloc(size, sizeof(int));

	/* Count occurrences of each element */
	for (i = 0; i < size; i++)
		counter[array[i]]++;

	/* Get cumulative sum of counts */
	for (i = 1; i <= max_value; i++)
		counter[i] += counter[i - 1];

	/* Build sorted array */
	for (i = size - 1; i < size; i--)
	{
		sorted_array[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	/* Copy sorted array to original array */
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	/* Free allocated memory */
	free(sorted_array);
	free(counter);
}

