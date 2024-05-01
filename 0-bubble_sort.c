#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order using bubble sort
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (size_t b = 0; b < size - 1; b++)
	{
		int swapped = 0;

		for (size_t a = 0; a < size - b - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				int temp = array[a];

				array[a] = array[a + 1];
				array[a + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
