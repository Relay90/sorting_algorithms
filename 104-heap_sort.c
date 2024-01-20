#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index start
 * @array: The array to sort
 * @size: The size of the array
 * @start: The root of the heap to repair
 * @end: The end index of the heap
 **/
static void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start, child, swap;
	int temp;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap == root)
			return;

		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		root = swap;

		print_array(array, size);
	}
}

/**
 * heap_sort - Sorts an array using the Heap sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int temp;

	if (!array || size < 2)
		return;

	for (int i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size - 1);
	for (int end = size - 1; end > 0; end--)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;

		print_array(array, size);
		sift_down(array, size, 0, end - 1);
	}
}
