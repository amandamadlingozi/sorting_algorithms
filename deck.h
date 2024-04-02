#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum card_suit - Enumeration of card suits.
 * @SPADE: Spades suit.
 * @HEART: Hearts suit.
 * @CLUB: Clubs suit.
 * @DIAMOND: Diamonds suit.
 */
typedef enum card_suit
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} suit_t;

/**
 * struct playing_card - Structure representing a playing card.
 * @value: Value of the card from "Ace" to "King".
 * @suit: Suit of the card.
 */
typedef struct playing_card
{
	const char *value;
	const suit_t suit;
} card_t;

/**
 * struct deck_node - Structure representing a node in a deck of cards.
 * @card: Pointer to the card of the node.
 * @prev: Pointer to the previous node in the deck.
 * @next: Pointer to the next node in the deck.
 */
typedef struct deck_node
{
	const card_t *card;
	struct deck_node *prev;
	struct deck_node *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif

