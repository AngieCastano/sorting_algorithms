#include "sort.h"
void swap_prev(listint_t *node);
listint_t *forward(listint_t *start_elemet, listint_t **list);
void backward(listint_t *start_elemet, listint_t **list);
/**
 * cocktail_sort_list - cocktail_sort_list
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL)
		return;
	listint_t *end_rest = NULL;

        end_rest = forward(*list, list);
	printf("end_rest->n = %i\n", end_rest->n);
//	printf("before backward\n");
//        backward(end_rest, list);
//	printf("after backward\n");
}
/**
 * forward - coktail helper, lets the biggest at the end
 * @start_elemet: start element from wher start to search the biggest number
 */
listint_t *forward(listint_t *start_elemet, listint_t **list)
{
	listint_t *curr, *temp_n;

	curr = start_elemet->next;
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
					curr = curr->next;
					printf("curr->n = %i\n", curr->n);
				}
				else
					break;
			}
			curr = temp_n;
		}
		else
			curr = curr->next;
	}
	printf("curr->pev->n = %i\n", curr->prev->n);
	return (NULL);
}
/**
 * backward - coktail helper, lets the smallest at the beginning
 * @start_elemet: start element of the end
 * @list: list to print
 */
void backward(listint_t *start_elemet, listint_t **list)
{
	listint_t *curr;

	if (list == NULL || *list == NULL)
		return;
	curr = start_elemet->next;
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
			else
				break;
		}
	}
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
