#include "deck.h"
#include <stdio.h>

/**
 * custom_strcmp - Compare two strings
 * @str1: String
 * @str2: String
 *
 * Return: 1 if str1 and str2 are equal, 0 otherwise
 */
int custom_strcmp(const char *str1, char *str2)
{
	size_t i = 0;

	if (str1 == '\0')
		return (0);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] == '\0' && str2[i])
		return (0);
	return (1);
}

/**
 * get_card_value - Return the value of a card
 * @node: Represent the card
 *
 * Return: The card position
 */
int get_card_value(deck_node_t *node)
{
	int value;

	value = (*node).card->value[0] - '0';
	if (value < 50 || value > 57)
	{
		if (custom_strcmp((*node).card->value, "Ace") == 1)
			value = 1;
		else if (custom_strcmp((*node).card->value, "10") == 1)
			value = 10;
		else if (custom_strcmp((*node).card->value, "Jack") == 1)
			value = 11;
		else if (custom_strcmp((*node).card->value, "Queen") == 1)
			value = 12;
		else if (custom_strcmp((*node).card->value, "King") == 1)
			value = 13;
	}
	value += (*node).card->kind * 13;
	return (value);
}

/**
 * swap_card_nodes - Swap a card node with its previous one
 * @card: Card node
 * @deck: Card deck
 *
 * Return: A pointer to the card which was swapped
 */
deck_node_t *swap_card_nodes(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *current = card;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;
	return (current);
}

/**
 * insertion_sort_deck - Sort a doubly linked deck
 * of integers in ascending order using the Insertion sort algorithm
 * @deck: Double linked deck to sort
 */
void insertion_sort_deck(deck_node_t **deck)
{
	int prev_value, current_value;
	deck_node_t *node;

	if (deck == NULL || (*deck)->next == NULL)
		return;
	node = (*deck)->next;
	while (node)
	{
		if (node->prev)
		{
			prev_value = get_card_value((node->prev));
			current_value = get_card_value(node);
		}
		while ((node->prev) && (prev_value > current_value))
		{
			prev_value = get_card_value((node->prev));
			current_value = get_card_value(node);
			node = swap_card_nodes(node, deck);
		}
		node = node->next;
	}
}

/**
 * sort_deck - Sort a deck using insertion sort algorithm
 * @deck: Deck
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}
