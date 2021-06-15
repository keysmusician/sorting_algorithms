#include "sort.h"

/**
 * partition - Partition an array of integers for use in the Quick sort
 * algorithm.
 * @array: array
 * @start: start index
 * @end: end index
 * Return: next pivot index
 */
size_t partition(int *array, size_t start, size_t end)
{
	size_t i, pivot_index = start;
	int temp, pivot = array[end];

	for (i = start; i < end; i++)
	{
		if (array[i] < pivot)
		{
			/* Swap array[i] <-> array[pivot_index] */
			temp = array[i];
			array[i] = array[pivot_index];
			array[pivot_index] = temp;
			print_array(array, end);

			pivot_index++;
		}
	}
	/* Swap array[end] <-> array[pivot_index] */
	temp = array[end];
	array[end] = array[pivot_index];
	array[pivot_index] = temp;

	return (pivot_index);
}

/**
 * quicksort - Sort an array of integers in ascending order using the
 * Quick sort algorithm.
 * @array: array
 * @start: start index
 * @end: end index
 */
void quicksort(int *array, size_t start, size_t end)
{
	size_t pivot_index;

	if (start < end && end > 0)
	{
		pivot_index = partition(array, start, end);
		quicksort(array, start, pivot_index - 1);
		quicksort(array, pivot_index + 1, end);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order using the
 * Quick sort algorithm.
 * @array: array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size);
}
