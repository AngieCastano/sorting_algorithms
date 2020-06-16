#include "sort.h"
/**
 * quick_sort - quick_sort
 * @array: array
 * @size: size
 */
void quick_sort(int *array, size_t size)
{

	if (!array || (!*array || size < 2))
		return;
	quick_helper(array, size, 0, size - 1);
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

	if (start <= end)
		return;
	pivot = partition(array, size, start, end);
	quick_helper(array, size, start, pivot - 1);
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
	int i = 0, j = 0, pivot = array[end], tmp = 0;

	for (j = start; j <= end; j++)
	{
		if (array[j] <= pivot)
		{
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			i++;
			print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = tmp;
	print_array(array, size);
	return(i + 1);
}
