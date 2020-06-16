#include "sort.h"
/**
 * quick_sort - quick_sort
 * @array: array
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 1)
		return;
	quick_helper(array,size,0,size - 1);
}
/**
 * quick_helper - quick  helpre
 * @array: array
 * @size: size
 * @start: beginning
 * @end: end
 */
void quick_helper(int *array, int size, int start, int end)
{
	int pivot = 0;

	if (start >= end)
		return;
	pivot = partition(array, size, start, end);
        quick_helper(array, size, start, pivot -1);
	quick_helper(array, size, pivot, end);
}
/**
 * partition - partition
 * @array: array
 * @size: size
 * @start: beginning
 * @end: end
 * Return: pivot
 */
int partition(int *array, int size, int start, int end)
{
        int left, right, pivot;

	left = start - 1;
	right = end + 1;
	pivot = array[end];
	while (1)
	{
		do {
			left++;
		} while (array[left] < pivot);
		do {
			right--;
		} while (array[right] > pivot);
		if (left < right)
		{
			swap(array, left, right);
			print_array(array, size);
		}
		else
			return (left);
	}
	
}
/**
 * swap - swaps two position given the array
 * @array: array to elements
 * @index_a: index a to swap
 * @index_b: index b to swap
 */
void swap(int *array, int index_a, int index_b)
{
	int temp;

	temp = array[index_a];
	array[index_a] = array[index_b];
	array[index_b] = temp;
}

