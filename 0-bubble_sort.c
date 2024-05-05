#include "sort.h"

/**
 *bubble_sort - sorts an array of int in an ascending orde
 *@array: the array of numbers
 *@size: the Size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int temp;

	if (array == NULL  || size < 2)
		return;
	for (b = 0; b < size - 1; b++)
	{
		for (a = 0; a < size - b - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				temp = array[a];
				array[a] = array[a + 1];
				array[a + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
