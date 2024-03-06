#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	merge_sort_recursive(array, 0, size - 1);
}

/**
 * merge_sort_recursive - Recursive helper function for merge_sort
 * @array: The array to be sorted
 * @start: The starting index of the subarray
 * @end: The ending index of the subarray
 */
void merge_sort_recursive(int *array, size_t start, size_t end)
{
	if (start < end)
	{
		size_t middle = start + (end - start) / 2;

		printf("Merging...\n");
		printf("[left]: ");
		print_array(array + start, middle - start + 1);
		printf("[right]: ");
		print_array(array + middle + 1, end - middle);

		merge_sort_recursive(array, start, middle);
		merge_sort_recursive(array, middle + 1, end);

		printf("[Done]: ");
		merge(array, start, middle, end);
		print_array(array + start, end - start + 1);
	}
}

/**
 * merge - Merges two subarrays into a sorted array
 * @array: The array containing the subarrays
 * @start: The starting index of the first subarray
 * @middle: The ending index of the first subarray
 * @end: The ending index of the second subarray
 */
void merge(int *array, size_t start, size_t middle, size_t end)
{
	size_t i, j, k;
	size_t size_left = middle - start + 1;
	size_t size_right = end - middle;

	int *left = malloc(size_left * sizeof(int));
	int *right = malloc(size_right * sizeof(int));

	if (left == NULL || right == NULL)
	{
		free(left);
		free(right);
		return;
	}
	for (i = 0; i < size_left; ++i)
		left[i] = array[start + i];
	for (j = 0; j < size_right; ++j)
		right[j] = array[middle + 1 + j];
	i = 0;
	j = 0;
	k = start;
	while (i < size_left && j < size_right)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			++i;
		}
		else
		{
			array[k] = right[j];
			++j;
		}
		++k;
	}
	while (i < size_left)
	{
		array[k] = left[i];
		++i;
		++k;
	}
	while (j < size_right)
	{
		array[k] = right[j];
		++j;
		++k;
	}
	free(left);
	free(right);
}

