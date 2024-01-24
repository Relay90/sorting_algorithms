#include "sort.h"
#include <stdio.h>

/**
 * swap - utility function to swap to integers
 * @a: integer a
 * @b: integer b
 **/
void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

/**
 * maxHeapify - The main function to heapify a Max Heap. The function
 * assumes that everything under given root (element at index idx)
 * is already heapified
 * @array: array
 * @size: size of the array for print
 * @index: the index of the current root element
 * @n: size of the array to run
 */
void maxHeapify(int *array, size_t size, int index, size_t n)
{
	const int root = index;
	const int left = 2 * index + 1;
	const int right = 2 * index + 2;

	int largest = root;

	if (left < (int)n && array[left] > array[largest])
		largest = left;

	/**
	 * see if right child of root exists and is greater than
	 * the largest so far
	 */
	if (right < (int)n && array[right] > array[largest])
		largest = right;

	/* change root, if neede */

	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		maxHeapify(array, size, largest, n);
	}
}
/**
 * heap_sort -  The main function to sort an array of given size
 * @array: array to sort
 * @size: size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		maxHeapify(array, size, i, size);

	for (i = (size - 1); i > 0; --i)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);

		/* Finally, heapify the root of tree.*/
		maxHeapify(array, size, 0, i);
	}
}
