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
        int pivot = array[end];
	int left = start, j, tmp1;
	for(j = start; j < end; j++)
	{
		if(array[j] <= pivot)
		{
			if (left != j)
			{
				tmp1 = array[left];
				array[left] = array[j];
				array[j] = tmp1;
				print_array(array, size);
			}
			left++;
		}
	}
	if (left != end)
	{
		tmp1 = array[left];
		array[left] = array[end];
		array[end] = tmp1;
		print_array(array,size);
	}
	return(left);
}

