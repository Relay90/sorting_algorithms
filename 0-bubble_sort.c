#include "sort.h"

/**
 * bubble_sort - sort array elements in ascending order using Bubble Sort
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, index;
	int tmp;
	int swapped;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (index = 0; index < size - i - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				tmp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = tmp;

				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped == 0)
			break;
	}
}
