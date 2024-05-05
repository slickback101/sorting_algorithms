#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort.
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 */

void shell_sort(int *array, size_t size)
{
    unsigned int gap = 1, a, b;
	int temp;

    if (array == NULL || size < 2)
        return;

    gap = 1;
    while (gap < size / 3)
        gap = gap * 3 + 1;

    while (gap > 0)
    {
        for (a = gap; a < size; a++)
        {
            temp = array[a];
            b = a;

            while (b >= gap && array[b - gap] > temp)
            {
                array[b] = array[b - gap];
                b -= gap;
            }

            array[b] = temp;
        }

        gap /= 3;

        print_array(array, size);
    }
}
