#include "sort.h"

/**
 * swap_node - swap a node with its previous one
 * @node: node to be swapped
 * @list: pointer to the head of the list
 * Return: pointer to the swapped node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;

	if (current->prev)
		current->prev->next = current;
	else
		*list = current;

	return (current);
}

/**
 * cocktail_sort_list - sort a doubly linked list using Cocktail Shaker Sort
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node = *list;
	int swaps_occurred = 1;

	if (!list || !(*list) || !(*list)->next)
		return;

	while (swaps_occurred == 1)
	{
		swaps_occurred = 0;

		for (; node->next; node = node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				swaps_occurred = 1;
				print_list(*list);
			}
		}

		if (swaps_occurred == 0)
			break;

		swaps_occurred = 0;

		for (; node->prev; node = node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				swaps_occurred = 1;
				print_list(*list);
			}
		}
	}
}
