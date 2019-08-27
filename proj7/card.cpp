/* Michael Ziegler                                           CARD_IMPLIMENTATION
 * CSCI 3110-001
 * Project #7
 * Due: 03/15/19
 * 
 * File: card.cpp
 * Purpose: Card class implimentation for proj7 executable.
 */
 
#include "priorityqueue.h"
using std::cout;

/*(1)(CONSTRUCTOR)
 *	Purpose: Accepts as arguments face-card value, and suit; sets the card's
 * appropriate point value, and initialized the suit and face values provided.*/
Card::Card()
{}

Card::Card(int face, suit st)
{
	cardSuit = st;
	cardFace = face;

}

/*(2)(<<_OVERLOAD)
 *	Purpose: Overloads the insertion operator(<<), for use with the "Card" 
 *   class. Initialized all card Face/Suit_Values.							  */
std::ostream& operator << (ostream& os, const Card& cd)
{
	char suit = cd.cardSuit;	//holds the card's suit

								// print suit symbol
	if (suit == hearts)
		suit = 'H';
	else if (suit == diamonds)
		suit = 'D';
	else if (suit == clubs)
		suit = 'C';
	else if (suit == spades)
		suit = 'S';

	// prints the cardFace and cardSuit 
	if (cd.cardFace == 1)
		os << "A" << suit << "[" << cd.cardFace << "]" << "   ";
	else if (cd.cardFace > 1 && cd.cardFace < 10)
		os << cd.cardFace << suit << "[" << cd.cardFace << "]" << "   ";
	else if (cd.cardFace == 10)
		os << "10" << suit << "[" << cd.cardFace << "]" << " ";
	else if (cd.cardFace == 11)
		os << "J" << suit << "[" << cd.cardFace << "]" << "  ";
	else if (cd.cardFace == 12)
		os << "Q" << suit << "[" << cd.cardFace << "]" << "  ";
	else if (cd.cardFace == 13)
		os << "K" << suit << "[" << cd.cardFace << "]" << "  ";
	return os;
}

/*(3)(<=_OVERLOAD)
 *	Purpose: Overloads the "less-than" operator(<), for use with the "Card" 
 *   class.																	  */
bool Card:: operator <= (const Card& cd) const
{
	if (cardFace <= cd.cardFace)
		return true;
	else
		return false;
}

/*(3)(>=_OVERLOAD)
 *	Purpose: Overloads the "greater-than" operator(>), for use with the "Card" 
 *   class.																	  */
bool Card:: operator >= (const Card& cd) const
{
	if (cardFace >= cd.cardFace)
		return true;
	else
		return false;
}

/*(4)(==_OVERLOAD)
 *	Purpose: Overloads the equals operator(==), for use with the "Card" 
 *   class. 																  */
bool Card::operator== (const Card& cd) const
{
	if (cardFace == cd.cardFace)
		return true;
	else
		return false;
}

