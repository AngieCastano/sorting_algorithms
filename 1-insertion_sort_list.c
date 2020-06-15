#include "sort.h"
/**
 * insertion_sort_list - insertion sort algorith
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *tmp2;

	if (!list || !(*list))
		return;
	tmp = *list;
	while (tmp->next && tmp)
	{
		if (tmp->next->n < tmp->n)
		{
			if (tmp->next->next)
			{
				tmp->next = tmp->next->next;
				tmp->next->prev->prev = tmp->prev;
				tmp->prev = tmp->next->prev;
				tmp->next->prev->next = tmp;
				tmp->next->prev = tmp;
				if (tmp->prev->prev)
					tmp->prev->prev->next = tmp->prev;
				print_list(*list);
				tmp2 = tmp;
				swap_in_reverse(tmp2, list);
			}
			else
			{
				tmp->next->prev = tmp->prev;
				tmp->next->next = tmp;
				tmp->prev = tmp->next;
				tmp->next = NULL;
				tmp->prev->prev->next = tmp->prev;
				print_list(*list);
				tmp = swap_in_reverse(tmp2, list);
				*list = tmp;
			}
		}
		else
			tmp = tmp->next;
	}
}

/**
 * swap_in_reverse- swaps backwards
 * @tmp: temporal from whar to swap in reverse
 * @list: list to print
 * Return: the temporal pointer address
 */
listint_t *swap_in_reverse(listint_t *tmp, listint_t **list)
{
	while (tmp->prev && tmp)
	{
		if (tmp->prev->n > tmp->n)
		{
			if (tmp->prev->prev)
			{
				tmp->prev = tmp->prev->prev;
				tmp->prev->next->next = tmp->next;
				tmp->next = tmp->prev->next;
				tmp->prev->next->prev = tmp;
				tmp->prev->next = tmp;
				if (tmp->next->next)
					tmp->next->next->prev = tmp->next;
				print_list(*list);

			}
			else
			{
				tmp->prev->next = tmp->next;
				tmp->prev->prev = tmp;
				tmp->next = tmp->prev;
				tmp->prev = NULL;
				tmp->next->next->prev = tmp->next;
				*list = tmp;
				print_list(*list);
			}
		}
		else
			tmp = tmp->prev;
	}
	return (tmp);
}
