#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0];
	size_t i;
	int i;
	int *count, *output;

	if (array == NULL || size <= 1)
		return;
	for (i = 1; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;
	for (i = 0; i <= max; ++i)
		count[i] = 0;
	for (i = 0; i < size; ++i)
		count[array[i]]++;
	for (i = 1; i <= max; ++i)
		count[i] += count[i - 1];
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (i = size - 1; i >= 0; --i)
		output[count[array[i]] - 1] = array[i];
	for (i = 0; i < size; ++i)
		array[i] = output[i];
	printf("%d", count[0]);
	for (i = 1; i <= max; ++i)
		printf(", %d", count[i]);
	printf("\n");
	free(count);
	free(output);
}
