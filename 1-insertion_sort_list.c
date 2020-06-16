#include "sort.h"
/**
 * insertion_sort_list - insertion sort algorith
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp_n;

	if (list == NULL || *list == NULL)
		return;
	curr = (*list)->next;
	while (curr != NULL)
	{
		if (curr->prev->n > curr->n)
		{
			temp_n = curr->next;
			while (curr->prev != NULL)
			{
				if (curr->n < curr->prev->n)
				{
					swap_prev(curr);
					while ((*list)->prev != NULL)
						(*list) = (*list)->prev;
					print_list(*list);
				}
				else
					break;
			}
			curr = temp_n;
		}
		else
			curr = curr->next;
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
        listint_t *pp, *p, *n;

	if (node->prev == NULL)
		return;
	p = node->prev;
	pp = p->prev;
	n = node->next;
	if (pp != NULL)
		pp->next = node;
	node->prev = pp;
	node->next = p;
	p->prev = node;
	p->next = n;
	if (n != NULL)
		n->prev = p;
}
