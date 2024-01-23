#include "sort.h"

/**
 * selection_sort - sotes an array using selection sort algorithm
 * @array: the array being sorted
 * @size: the size of the array being sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, smallest = 0;
	int temp;

	while (i < size)
	{
		j = i;
		smallest = i;
		while (j < size)
		{
			if (array[smallest] > array[j])
				smallest = j;
			j++;
		}
		if (smallest != i)
		{
			temp = array[i];
			array[i] = array[smallest];
			array[smallest] = temp;
			print_array(array, size);
		}
		i++;
	}
}
