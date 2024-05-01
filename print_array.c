#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: Pointer to the array of integers
 * @size: Number of elements in the array
 */

void print_array(const int *array, size_t size)
{
    size_t a;

    if (array == NULL || size == 0)
    {
        printf("Array is empty or invalid\n");
        return;
    }

    for (size_t a = 0; a < size; a++)
    {
        if (a > 0)
            printf(", ");
        printf("%d", array[a]);
    }
    printf("\n");
}
