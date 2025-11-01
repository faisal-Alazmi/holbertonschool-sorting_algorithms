#include "sort.h"

/**
 * swap_nodes - Swap two adjacent nodes a (before) and b (after) in a DLL
 * @list: Address of head pointer
 * @a: First node (must be before b)
 * @b: Second node (a->next)
 */
static void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *ap = a->prev, *bn = b->next;

	if (ap)
		ap->next = b;
	b->prev = ap;

	b->next = a;
	a->prev = b;

	a->next = bn;
	if (bn)
		bn->prev = a;

	if (!b->prev)
		*list = b;
}

/**
 * insertion_sort_list - Sort a doubly linked list using Insertion sort
 * @list: Address of head pointer
 *
 * Description: Swaps *nodes* (not values) and prints after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *scan;

	if (!list || !*list || !(*list)->next)
		return;

	cur = (*list)->next;
	while (cur)
	{
		scan = cur;
		while (scan->prev && scan->prev->n > scan->n)
		{
			swap_nodes(list, scan->prev, scan);
			print_list(*list);
		}
		cur = scan->next;
	}
}
