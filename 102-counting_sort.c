#include "sort.h"
/**
 * get_max_val - gets the maximum value element in an array of integers
 * @arr: array of integers
 * @size: size of the array
 * Return: integer with maximum value in the array
 */
int get_max_val(int *arr, int size)
{
	int max = arr[0];
	int i;

	for (i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}
/**
 * counting_sort - sorts an array of integers in ascending order,
 * using the Counting sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array to be sorted
 */
void counting_sort(int *array, size_t size)
{
	int *count;
	size_t *output, k, i;

	if (array == NULL || size < 2)
		return;
	output = malloc(sizeof(size_t) * size);
	if (output == NULL)
		return;
	k = get_max_val(array, size);
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
	{
		free(output);
		return;
	}

	for (i = 0; i < (k + 1); i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		++count[array[i]];
	for (i = 0; i < (k + 1); i++)
		count[i] += count[i - 1];
	print_array(count, k + 1);

	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		--count[array[i]];
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}
