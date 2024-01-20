#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection Sort algorithm.
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, index, tmp, swap, flag;

	for (i = 0; i < size; i++)
	{
		tmp = i;
		flag = 0;

		for (index = i + 1; index < size; index++)
		{
			if (array[index] < array[tmp])
			{
				tmp = index;
				flag = 1;
			}
		}

		if (flag != 0)
		{
			swap = array[i];
			array[i] = array[tmp];
			array[tmp] = swap;
			print_array(array, size);
		}
	}
}
