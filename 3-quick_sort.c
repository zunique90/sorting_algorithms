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
 * Return: i
 */
int lomuto_partition(int *arr, int first, int last, size_t size)
{
	int pivot = arr[last];
	int i = first;
	int j;

	for (j = first; j < last; j++)
	{
		if (arr[j] <= pivot)
		{
			swap_ints(&arr[i], &arr[j]);
			if (i != j)
				print_array(arr, size);
			i++;
		}
	}
	swap_ints(&arr[i], &arr[last]);
	if (i != j)
		print_array(arr, size);
	return (i);
}

/**
 * lomuto_sort - sorts a partition of the array
 * @arr: array
 * @first: first element
 * @last: last element
 * @size: size
 */
void lomuto_sort(int *arr, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = lomuto_partition(arr, first, last, size);
		lomuto_sort(arr, first, pivot - 1, size);
		lomuto_sort(arr, pivot + 1, last, size);
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
