#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - swaps two elements of array
 * @array: the array whose elements are being swaped
 * @a: element index being swaped
 * @b: the other element index being swaped
 * @size: the size of the array
 */
void swap(int *array, int a, int b, size_t size)
{
	int tmp = array[a];

	array[a] = array[b];
	array[b] = tmp;

	print_array(array, size);
}

/**
 * lomutoPartition - moves every element less than @last to the left
 * and position the last to the right sorted position
 * @array: the array being partitioned and sorted
 * @begin: the starting point
 * @last: the last position
 * @size: the size of the array
 * Return: returns the last position of the pivot(@last) element
 */
int lomutoPartition(int *array, int begin, int last, size_t size)
{
	int pivot = last;
	int position = begin - 1;
	int i = begin;

	while (i < last)
	{
		if (array[i] <= array[pivot])
		{
			position++;
			if (i > position)
			{
				swap(array, i, position, size);
			}
		}
		i++;
	}
	if (pivot != ++position)
		swap(array, pivot, position, size);
	return (position);
}

/**
 * recurser - recurser function for quick_sort
 * @array: the array being sorted
 * @begin: the starting point of partitioned or orignal function
 * @last: the last point of partitioned or orignal function
 * @size: the size of the array
 */
void recurser(int *array, int begin, int last, size_t size)
{
	if (begin < last)
	{
		int partitionpoint = lomutoPartition(array, begin, last, size);

		recurser(array, begin, partitionpoint - 1, size);
		recurser(array, partitionpoint + 1, last, size);

	}
}
/**
 * quick_sort - sotrs an array using quicksort algorithm
 * @array: the array bing sorted
 * @size: the size of the array being sorted
 */
void quick_sort(int *array, size_t size)
{
	recurser(array, 0, size - 1, size);
}
