#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * partition - Partitions an array using the Lomuto partition scheme.
 * @array: Array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 * Return: Index of the pivot element.
 */

int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    swap(&array[i + 1], &array[high]);
    print_array(array, size);

    return (i + 1);
}

/**
 * lomuto_qsort - Sorts an array recursively using the Lomuto partition scheme.
 * @array: Array to be sorted.
 * @low: Starting index of the subarray to be sorted.
 * @high: Ending index of the subarray to be sorted.
 * @size: Size of the array.
 */

void lomuto_qsort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = partition(array, low, high, size);

        lomuto_qsort(array, low, pi - 1, size);
        lomuto_qsort(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 *              with Lomuto partitioning.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_qsort(array, 0, size - 1, size);
}
