/* Michael Ziegler                                           DECK_IMPLIMENTATION
 * CSCI 3110-001
 * Project #4
 * Due: 02/28/19
 * 
 * File: deck.cpp
 * Purpose: Deck class implimentation for proj4 executable.
 */
 #include <algorithm>
#include "deck.h"
using std::begin;
using std::end;
using std::random_shuffle;

/*(1)(CONSTRUCTOR)
 *	Purpose: Initialized the deck values by suit, and calls the Card constructer
 52 times setting each Face Value, point value, and the appropriate Card Suit.*/
Deck::Deck()
{
	for (int i = 0; i <= 12; i++)
	{
		this->theDeck[i] = Card((i - 0), clubs);
	}
	for (int i = 13; i <= 25; i++)
	{
		this->theDeck[i] = Card((i - 13), hearts);
	}
	for (int i = 26; i <= 38; i++)
	{
		this->theDeck[i] = Card((i - 26), spades);
	}
	for (int i = 39; i <= 51; i++)
	{
		this->theDeck[i] = Card((i - 39), diamonds);
	}
	this->topCard = 51;
}

/*(2)(PLAYCARD)
 *	Purpose: Returns a single card from the top of the deck*/
Card Deck::dealCard()
{
		this->topCard--;
		return this->theDeck[this->topCard + 1];
}

/*(3)(SHUFFLE)
 *	Purpose: Used std::random_shuffle, std::iterators begin(), and end(), along
 * along with a random seed from standard input to shuffle the deck to spec.  */
void Deck::Shuffle()
{
	random_shuffle(begin(theDeck), end(theDeck));
}

/*(4)(ISEMPTY)
 *	Purpose: Checks if the deck is empty, return true if it is empty, and false
 *  if it is not empty.														  */
bool Deck::isEmpty()
{
	if (this->topCard == -1)
		return true;
	else
		return false;
}

/*(5)(<<_OVERLOAD)
 *	Purpose: Overloads the insertion operator(<<), for use with the "Deck" 
 *   class. Prints out the entire deck in the appropriate format 13 Cards/ln. */
ostream& operator<<(ostream& os, const Deck& dk)
{
	for (int i = 51; i >= 0; i--)
	{
		if (i == 39 || i == 26 || i == 13 || i == 0)
			os << dk.theDeck[i] << std::endl;
		else
			os << dk.theDeck[i] << " ";
	}
	return os;
}
