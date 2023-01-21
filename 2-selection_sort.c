#include "sort.h"

/**
 * swap_ints - swaps two integers
 * @a: pointer to first int
 * @b: pointer to second int
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts an array of integers in ascending order,
 * using the Selection sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min = 0;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (i != min)
		{
			swap_ints(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
