#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

static void merge(int *array, size_t left, size_t mid, size_t right);
static void merge_sort_recursive(int *array, size_t left, size_t right);

/**
 * merge_sort - Perform merge sort on an array of integers
 * @array: The array to be sorted
 * @size: Total size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, 0, size);
}

/**
 * merge_sort_recursive - Recursive function to perform merge sort
 * @array: The array to be sorted
 * @left: Start index of the sub-array
 * @right: End index of the sub-array
 */
static void merge_sort_recursive(int *array, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
        mid = (left + right) / 2;
	merge_sort_recursive(array, left, mid);
	merge_sort_recursive(array, mid, right);
	merge(array, left, mid, right);
	}
}

/**
 * merge - Merge two sub-arrays into one sorted array
 * @array: The array to be sorted
 * @left: Start index of the left sub-array
 * @mid: Middle index of the array
 * @right: End index of the right sub-array
 */
static void merge(int *array, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;
	size_t n1 = mid - left;
	size_t n2 = right - mid;

	int *left_array = malloc(n1 * sizeof(int));
	int *right_array = malloc(n2 * sizeof(int));

	if (left_array == NULL || right_array == NULL)
	{
		free(left_array);
		free(right_array);
		return;
	}

	printf("Merging...\n[left]: ");

	for (i = 0; i < n1; ++i)
		left_array[i] = array[left + i];

	for (j = 0; j < n2; ++j)
		right_array[j] = array[mid + j];

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (left_array[i] <= right_array[j])
			array[k++] = left_array[i++];
		else
			array[k++] = right_array[j++];
	}

	while (i < n1)
		array[k++] = left_array[i++];

	while (j < n2)
		array[k++] = right_array[j++];

	printf("[right]: ");
	for (i = mid; i < right; ++i)
	{
		printf("%d", array[i]);
		if (i < right - 1)
			printf(", ");
	}
	printf("\n[Done]: ");
	for (i = left; i < right; ++i)
	{
		printf("%d", array[i]);
		if (i < right - 1)
			printf(", ");
	}
	printf("\n");

	free(left_array);
	free(right_array);
}
