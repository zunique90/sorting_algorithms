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
 * shell_sort - sorts an array of integers in ascending,
 * order using the Shell sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, m, n;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (m = gap; m < size; m++)
		{
			n = m;
			while (n >= gap && array[n - gap] > array[n])
			{
				swap_ints(array + n, array + (n - gap));
				n -= gap;
			}
		}
		print_array(array, size);
	}
}
