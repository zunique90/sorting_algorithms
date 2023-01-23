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
 * lomuto_partition - partition an array around pivot
 * @arr: the array to be partitioned
 * @first: first element
 * @last: last element
 * @size: size
 * Return: i - index of the final partition
 */
int lomuto_partition(int *arr, size_t size, int first, int last)
{
	int *pivot = arr + last;
	int i, j;

	for (j = i = first; j < last; j++)
	{
		if (arr[j] < *pivot)
		{
			if (i < j)
			{
				swap_ints(arr + j, arr + i);
				print_array(arr, size);
			}
			i++;
		}
	}
	if (arr[i] > *pivot)
	{
		swap_ints(arr + i, pivot);
		print_array(arr, size);
	}
	return (i);
}

/**
 * lomuto_sort - sorts a partition of the array
 * @arr: array
 * @first: first element
 * @last: last element
 * @size: size
 */
void lomuto_sort(int *arr, size_t size, int first, int last)
{
	int pivot;

	if (last - first > 0)
	{
		pivot = lomuto_partition(arr, size, first, last);
		lomuto_sort(arr, size, first, pivot - 1);
		lomuto_sort(arr, size, pivot + 1, last);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: An array of integers.
 * @size: The size of the array.
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
