#include "sort.h"
/**
 * bubble_sort - bubble sort algorithm
 * @array: array to sort
 * @size: array's size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t temp = 0;
	int validations = 0;

	if (size < 2 || !array)
		return;
	for (i = 0; array[i]; i++)
	{
		temp = 0;

		if (i < size - 1 && array[i + 1] < array[i])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			print_array(array, size);
			validations++;
		}
		if (i == size - 1)
		{
			i = -1;
			if (validations == 0)
			{
				return;
			}
			validations = 0;
		}
	}
}
