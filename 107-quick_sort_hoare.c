#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @array: array
 * @a: index of the first element
 * @b: index of the second element
 */
void swap(int *array, int a, int b)
{
	if (array[a] != array[b])
	{
		array[a] ^= array[b];
		array[b] ^= array[a];
		array[a] ^= array[b];
	}
}

/**
 * hoare_partition - Hoare partition scheme for quicksort
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 * Return: partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap(array, i, j);
			print_array(array, size);
		}
		else
			return (j);
	}
}

/**
 * quick_sort_hoare_recursive - recursive helper function for quick_sort_hoare
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 */
void quick_sort_hoare_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
	int partition_index = hoare_partition(array, low, high, size);

	quick_sort_hoare_recursive(array, low, partition_index, size);
	quick_sort_hoare_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using
 * the Quick sort algorithm (Hoare partition scheme)
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_hoare_recursive(array, 0, size - 1, size);
}
