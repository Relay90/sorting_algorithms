#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot element
 */
size_t lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int temp;
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            print_array(array, size);
        }
    }

    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    print_array(array, size);

    return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform quicksort
 * @array: Array to be sorted
 * @low: Starting index of the array or subarray
 * @high: Ending index of the array or subarray
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        size_t partition_index = lomuto_partition(array, low, high, size);

        if (partition_index != 0)
            quick_sort_recursive(array, low, partition_index - 1, size);

        quick_sort_recursive(array, partition_index + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
