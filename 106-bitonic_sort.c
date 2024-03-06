#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - Merge the bitonic sequences
 * @array: The array to be sorted
 * @start: The starting index of the sequence
 * @size: The size of the sequence
 * @dir: The direction of the sequence (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t start, size_t size, int dir)
{
	int temp;
	size_t mid;
	size_t i;

	if (size > 1)
	{
		mid = size / 2;
		for (i = start; i < start + mid; ++i)
		{
			if ((array[i] > array[i + mid]) == dir)
			{
				temp = array[i];
				array[i] = array[i + mid];
				array[i + mid] = temp;
				print_array(array, size);
			}
		}

		bitonic_merge(array, start, mid, dir);
		bitonic_merge(array, start + mid, mid, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursive function to perform Bitonic sort
 * @array: The array to be sorted
 * @start: The starting index of the sequence
 * @size: The size of the sequence
 * @dir: The direction of the sequence (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t start, size_t size, int dir)
{
	size_t mid;

	if (size > 1)
	{
		mid = size / 2;

		bitonic_sort_recursive(array, start, mid, 1);

		bitonic_sort_recursive(array, start + mid, mid, 0);

		bitonic_merge(array, start, size, dir);
	}
}

/**
 * bitonic_sort - Sort array of integers in ascending order using Bitonic sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 1);
}

