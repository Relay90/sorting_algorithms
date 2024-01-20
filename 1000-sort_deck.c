#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @a: first node
 * @b: second node
 */
void swap_nodes(deck_node_t *a, deck_node_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *next;
	int swapped;

	if (deck == NULL || *deck == NULL)
		return;

	do {
		swapped = 0;
		current = *deck;

		while (current->next)
		{
			next = current->next;

			if ((current->card->kind > next->card->kind) ||
		(current->card->kind == next->card->kind &&
		strcmp(current->card->value, next->card->value) > 0))
			{
				swap_nodes(current, next);
				if (*deck == current)
					*deck = next;

				swapped = 1;
				print_deck(*deck);
			}
			else
			{
				current = current->next;
			}
		}
	} while (swapped);
}
