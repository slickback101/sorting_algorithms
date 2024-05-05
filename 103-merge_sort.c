#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merge two subarrays into one sorted array.
 * @array: Original array to be sorted.
 * @l: Left subarray.
 * @r: Right subarray.
 * @size_left: Size of the left subarray.
 * @size_right: Size of the right subarray.
 */

void merge(int *array, int *l, int *r, size_t size_left, size_t size_right)
{
    size_t a = 0, b = 0, c = 0;

    while (a < size_left && b < size_right)
    {
        if (l[a] <= r[b])
            array[c++] = l[a++];
        else
            array[c++] = r[b++];
    }

    while (a < size_left)
        array[c++] = l[a++];

    while (b < size_right)
        array[c++] = r[b++];
}

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 */

void merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t mid;
	int a;

    if (array == NULL || size < 2)
        return; 

     mid = size / 2;
     
     int *left = (int *)malloc(sizeof(int) * mid);
     int *right = (int *)malloc(sizeof(int) * (size - mid));

    if (left == NULL || right == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (a = 0; a < mid; a++)
        left[a] = array[a];

    for (a = mid; a < size; a++)
        right[a - mid] = array[a];

    merge_sort(left, mid);
    merge_sort(right, size - mid);

    merge(array, left, right, mid, size - mid);

    free(left);
    free(right);
}
