#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two sorted subarrays into a single sorted subarray
 *
 * @array: The original array to be sorted
 * @temp: Temporary array used for merging
 * @left: The starting index of the left subarray
 * @mid: The starting index of the right subarray (middle point)
 * @right: The ending index (exclusive) of the right subarray
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
		temp[k++] = (array[i] <= array[j]) ? array[i++] : array[j++];

	while (i < mid)
		temp[k++] = array[i++];

	while (j < right)
		temp[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * top_down_split_merge - Recursively splits and merges array parts
 *
 * @array: The array to sort
 * @temp: A temporary array to store merged results
 * @left: Starting index of the current segment
 * @right: Ending index (exclusive) of the current segment
 */
void top_down_split_merge(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (right - left <= 1)
		return;

	mid = left + (right - left) / 2;

	top_down_split_merge(array, temp, left, mid);
	top_down_split_merge(array, temp, mid, right);
	merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers using top-down merge sort
 *
 * @array: The array to sort
 * @size: The number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	top_down_split_merge(array, temp, 0, size);
	free(temp);
}
