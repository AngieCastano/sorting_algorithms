#include "sort.h"
/**
 * shell_sort - sort array in shell format
 * @array: array to sort
 * @size: array size
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int temp, impri;
	size_t j, gap, k;

	if (array == NULL || size < 1)
		return;
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	for (; gap > 0; gap = gap / 3)
	{
		impri = 0;
		for (j = gap; j < size; j += 1)
		{
			temp = array[j];
			for (k = j; k >= gap && array[k - gap] > temp; k -= gap)
			{
				array[k] = array[k - gap];
			}
			array[k] = temp;
			impri = 1;
		}
		if (impri == 1)
			print_array(array, size);
	}
}
