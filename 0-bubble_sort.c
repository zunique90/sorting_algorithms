#include "sort.h"
/**
 * bubble_sort - Uses the bubble sort method to sort an array
 * @array: array to be sorted
 * @size: size of the array to be sorted
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int tmp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
