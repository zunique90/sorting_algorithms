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
 * hoare_partition - partition an array of integers,
 * according to the hoare partition scheme
 * @arr: the array to be partitioned
 * @first: index of first element
 * @last: index of last element
 * @size: size
 * Return: i - index of the final partition
 */
int hoare_partition(int *arr, size_t size, int first, int last)
{
	int pivot = arr[last];
	int i, j;

	for (i = first - 1, j = last + 1; i < j;)
	{
		do {
			i++;
		} while (arr[i] < pivot);
		do {
			j--;
		} while (arr[j] > pivot);

		if (i < j)
		{
			swap_ints(arr + i, arr + j);
			print_array(arr, size);
		}
	}
	return (i);
}
/**
 * hoare_sort - sorts a partition of the array
 * @arr: array
 * @first: first index of the partition to be sorted
 * @last: last index of the partition to be sorted
 * @size: size
 */
void hoare_sort(int *arr, size_t size, int first, int last)
{
	int pivot;

	if (last - first > 0)
	{
		pivot = hoare_partition(arr, size, first, last);
		hoare_sort(arr, size, first, pivot - 1);
		hoare_sort(arr, size, pivot, last);
	}
}
/**
 * quick_sort_hoare - sorts an array of integers in ascending order,
 * using the Quick sort algorithm
 * @array: an array of integers to be sorted
 * @size: the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_sort(array, size, 0, size - 1);
}
