#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the list.
 *
 * Description: Swaps the nodes themselves, not the integer values.
 * Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *next_iter, *prev_n;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		next_iter = curr->next;
		while (curr->prev != NULL && curr->prev->n > curr->n)
		{
			prev_n = curr->prev;
			
			/* Swap logic */
			prev_n->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = prev_n;
			
			curr->next = prev_n;
			curr->prev = prev_n->prev;
			prev_n->prev = curr;
			
			if (curr->prev != NULL)
				curr->prev->next = curr;
			else
				*list = curr;

			print_list(*list);
		}
		curr = next_iter;
	}
}
