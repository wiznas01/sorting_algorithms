#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort_hoare - Sorts array of integers using Quick sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_hoare_recurse(array, 0, size - 1, size);
}

/**
 * quick_sort_hoare_recurse - Recursively sorts the array using Quick sort
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 */
void quick_sort_hoare_recurse(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);

		if (pivot > 0)
			quick_sort_hoare_recurse(array, low, pivot - 1, size);

		quick_sort_hoare_recurse(array, pivot + 1, high, size);
	}
}

/**
 * hoare_partition - Partitions the array using the Hoare scheme
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 * Return: The index of the pivot
 */
size_t hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
		else
		{
			return (j);
		}
	}
}

