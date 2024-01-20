#include "sort.h"

/**
 * getMax - Get the maximum value in an array
 * @array: The array
 * @size: Size of the array
 * Return: The maximum value
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * countingSort - Perform counting sort on the specified digit
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: The current exponent for the specified digit
 */
void countingSort(int *array, size_t size, int exp)
{
	int *output;
	int count[10] = {0};
	size_t i;

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	/* Store count of occurrences in count[] */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size - 1; (int)i >= 0; i--) /* i is signed */
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Radix sort algorithm (LSD)
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
		print_array(array, size);
	}
}
