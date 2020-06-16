#include "sort.h"
/**
 * selection_sort - sorts an array with the selection sort algorithm
 * @array: array to sort
 * @size: array size
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, tmp = 0;
	int copy = 0;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		copy = i + 1;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[copy])
			{
				copy = j;
			}
			if (j == size - 1 && array[copy] < array[i])
			{
				tmp = array[i];
				array[i] = array[copy];
				array[copy] = tmp;
				print_array(array, size);
			}
		}
	}
}
