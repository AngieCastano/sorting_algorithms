#include "sort.h"
void swap_prev(listint_t *node);
listint_t *forward(listint_t *start_elemet, listint_t **list);
listint_t *backward(listint_t *start_elemet, listint_t **list);
void cocktail_helper(listint_t *start, listint_t *end, listint_t **list);
/**
 * cocktail_sort_list - cocktail_sort_list
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL)
		return;
	cocktail_helper(*list, NULL ,list);
}
/**
 * quick_helper - quick helper
 * @start: start of the list
 * @end: end of the list
 * @list: list
 */
void cocktail_helper(listint_t *start, listint_t *end, listint_t **list)
{
	if (list == NULL || *list == NULL)
		return;

	end = forward(*list, list);
	printf("end = %i\n", end->n);
	start = backward(end, list);
	printf("antes de llamarse\n");
	cocktail_helper(start, end, list);
}
/**
 * forward - coktail helper, lets the biggest at the end
 * @start_elemet: start element from wher start to search the biggest number
 */
listint_t *forward(listint_t *start_elemet, listint_t **list)
{
	listint_t *curr, *temp_n, *tmp_curr;

	curr = start_elemet->next;
	tmp_curr = curr;
	while (curr != NULL)
	{
		tmp_curr = curr;
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
					curr = curr->next;
				}
				else
					break;
			}
			curr = temp_n;
		}
		else
			curr = curr->next;
	}
	return (tmp_curr);
}
/**
 * backward - coktail helper, lets the smallest at the beginning
 * @start_elemet: start element of the end
 * @list: list to print
 */
listint_t *backward(listint_t *start_elemet, listint_t **list)
{
	listint_t *curr;

	if (list == NULL || *list == NULL)
		return(NULL);
	curr = start_elemet;
	if (curr != NULL)
	{
		while (curr->prev != NULL)
		{
			if (curr->n < curr->prev->n)
			{
				swap_prev(curr);
				while ((*list)->prev != NULL)
					(*list) = (*list)->prev;
				print_list(*list);
			}
		}
	}
	return(curr->prev);
}
/**
 * swap_prev - swaps the current node with its previous node
 * @node: node to swap
 */
void swap_prev(listint_t *node)
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
