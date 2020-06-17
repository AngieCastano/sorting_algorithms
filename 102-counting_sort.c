#include "sort.h"
/**
 * counting_sort - sort an array of ints using counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *c_array, *o_array;
	int l_num, j, idx, pl;
	size_t i;

	for (i = 0, l_num = 0; i < size; i++)
		if (array[i] > l_num)
			l_num = array[i];
	c_array = malloc(sizeof(int) * (l_num));
	if (c_array == NULL)
	{
		free(c_array)
		return;
	}
	o_array = malloc(sizeof(int) * (size));
	if (o_array == NULL)
	{
		free(o_array);
		return;
	}
	for (i = 0; i < size; i++)
		c_array[array[i]]++;
	for (j = 1; j < l_num + 1; j++)
		c_array[j] += c_array[j - 1];
	print_array(c_array, l_num + 1);
	for (i = 0; i < size; i++)
	{
		idx = array[i];
		pl = c_array[idx];
		o_array[pl - 1] = idx;
		c_array[idx]--;
	}
	for (i = 0; i < size; i++)
		array[i] = o_array[i];
	free(o_array);
	free(c_array);
}
