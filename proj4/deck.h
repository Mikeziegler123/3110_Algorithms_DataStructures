/* Michael Ziegler                                                    DECK_CLASS
 * CSCI 3110-001
 * Project #4
 * Due: 02/28/19
 * File: deck.h
 * Purpose: Deck class for proj4.cpp
 */
#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "card.h"

using std::ostream;

class Deck
{
public:

    // default constructor
	Deck();

    // Remove the top card from the deck and return it.
	Card dealCard();

    // Shuffle the cards in the deck
	void Shuffle();

    // return true if there are no more cards in the deck, false otherwise
	bool isEmpty();

    //overload << operator to display the deck
    friend ostream& operator << (ostream&, const Deck&);

private:
    static const int numCards = 52;		// # of cards in a deck
	Card    theDeck[numCards];			// the array holding the cards
	int     topCard;					// the index of the deck's top card
};

#endif

