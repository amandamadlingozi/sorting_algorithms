#include "sort.h"

void swap_integers(int *a, int *b);
void bitonic_merge_sort(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_sequence(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_integers - Swap two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_integers(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge_sort - Sort a bitonic sequence inside an array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 * @start: Starting index of the sequence to sort.
 * @seq: Size of the sequence to sort.
 * @flow: Direction to sort in.
 */
void bitonic_merge_sort(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == 'U' && array[i] > array[i + jump]) ||
					(flow == 'D' && array[i] < array[i + jump]))
				swap_integers(array + i, array + i + jump);
		}
		bitonic_merge_sort(array, size, start, jump, flow);
		bitonic_merge_sort(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_sequence - Convert an array of integers
 * into a bitonic sequence.
 * @array: Array of integers.
 * @size: Size of the array.
 * @start: Starting index of the bitonic sequence block.
 * @seq: Size of the bitonic sequence block.
 * @flow: Direction to sort the bitonic sequence block.
 */
void bitonic_sequence(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t cut = seq / 2;
	char *direction = (flow == 'U') ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, direction);
		print_array(array + start, seq);

		bitonic_sequence(array, size, start, cut, 'U');
		bitonic_sequence(array, size, start + cut, cut, 'D');
		bitonic_merge_sort(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, direction);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers
 * in ascending order using bitonic sort.
 * @array: Array of integers.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, 'U');
}
