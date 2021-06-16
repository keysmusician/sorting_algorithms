#include "sort.h"
/**
 * quick_sort - Sort an array of integers in ascending order using the
 * Quick sort algorithm.
 * @array: array
 * @size: size of array
 * // quicksort(array, 0, size);
 */
void quick_sort(int *array, size_t size)
{
	/* Indicies of pivot, item from left, item from right respectively */
	size_t P, L, R;
	int temp;
	static int *a, S = -1;

	/* Nothing to do if array is NULL or size < 2 */
	if (!array || size < 2)
		return;

	/* Save array pointer and size for printing */
	if (S == -1)
	{
		a = array;
		S = size;
	}

	/* Set pivot index to always be at the end of the list */
	P = size - 1;

	while (1)
	{
		/* Set L; Find the first value from the left larger than the pivot */
		for (L = 0; array[L] < array[P]; L++)
			continue;

		/* Set R; Find the first value from the right larger than the pivot */
		for (R = P - 1; array[R] > array[P] && R > 0; R--)
			continue;

		if (L < R)
		{
			/* Swap L & R */
			temp = array[L];
			array[L] = array[R];
			array[R] = temp;
			/* Display  */
			print_array(a, S);
		}
		else
			break;
	}
	if (L != P)
	{
		/* Swap L & P if they're not the same */
		temp = array[L];
		array[L] = array[P];
		array[P] = temp;
		/* array[L] is now sorted */
		print_array(a, S);
	}
	/* Quick sort the new partitions above and below L */
	quick_sort(array + L + 1, size - (L + 1));
	quick_sort(array, L);
}
