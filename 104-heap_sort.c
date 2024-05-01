#include "sort.h"

/**
 * heapify - Heapify a subtree rooted at given index.
 * @array: Array of integers.
 * @heap_size: Size of the heap.
 * @root_index: Root index of the subtree to heapify.
 * @size: Size of the array.
 */

void heapify(int *array, int heap_size, int root_index, int size)
{

    int largest = root_index;
    int left_child = 2 * root_index + 1;
    int right_child = 2 * root_index + 2;
    int temp;

    if (left_child < heap_size && array[left_child] > array[largest])
        largest = left_child;
    if (right_child < heap_size && array[right_child] > array[largest])
        largest = right_child;
    if (largest != root_index)
    {
        temp = array[root_index];
        array[root_index] = array[largest];
        array[largest] = temp;
        print_array(array, size);
        heapify(array, heap_size, largest, size);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 */

void heap_sort(int *array, size_t size)
{
    int a, temp;

    if (array == NULL || size < 2)
        return;

    for (a = size / 2 - 1; a >= 0; a--)
        heapify(array, size, a, size);

    for (a = size - 1; a > 0; a--)
    {

        temp = array[0];
        array[0] = array[a];
        array[a] = temp;
        print_array(array, size);

        heapify(array, a, 0, size);
    }
}
