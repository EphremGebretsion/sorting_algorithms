#include "sort.h"
#include <stddef.h>

/**
 * bubble_sort - used to sort an array using buble sort algorithm
 * @array: the array being sorted
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int temp;

	while (array && i < size)
	{
		j = 0;
		while (j < (size - 1))
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
}
