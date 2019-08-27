/* Michael Ziegler                                           CARD_IMPLIMENTATION
 * CSCI 3110-001
 * Project #4
 * Due: 02/28/19
 * 
 * File: card.cpp
 * Purpose: Card class implimentation for proj4 executable.
 */
#include "card.h"

Card::Card()
{
	this->cardSuit = diamonds;
	this->cardFace = -1;
	this->pointValue = -1;
}

/*(1)(CONSTRUCTOR)
 *	Purpose: Accepts as arguments face-card value, and suit; sets the card's
 * appropriate point value, and initialized the suit and face values provided.*/
Card::Card(int fc, suit st)
{
	cardSuit = st;
	cardFace = fc;

	switch (fc)
	{
	/*                 |Point|       										  */
	/*                 |Value|       										  */
	case 0: pointValue = 15;break;
	case 1: pointValue = 2 ;break;
	case 2: pointValue = 3 ;break;
	case 3: pointValue = 4 ;break;
	case 4: pointValue = 5 ;break;
	case 5: pointValue = 6 ;break;
	case 6: pointValue = 7 ;break;
	case 7: pointValue = 8 ;break;
	case 8: pointValue = 9 ;break;
	case 9: pointValue = 10;break;
	case 10:pointValue = 10;break;
	case 11:pointValue = 10;break;
	case 12:pointValue = 10;break;
	}
}

/*(2)(<<_OVERLOAD)
 *	Purpose: Overloads the insertion operator(<<), for use with the "Card" 
 *   class. Initialized all card Face_Values.								  */
ostream& operator<<(ostream& os, const Card& cd)
{
	switch (cd.cardFace)
	{
	case 0: switch (cd.cardSuit)
	{
	case 0: os << "A" << "C" << "[" << cd.pointValue << "]"; break;
	case 1: os << "A" << "H" << "[" << cd.pointValue << "]"; break;
	case 2: os << "A" << "S" << "[" << cd.pointValue << "]"; break;
	case 3: os << "A" << "D" << "[" << cd.pointValue << "]"; break;
	} break;
	case 1: switch (cd.cardSuit)
	{
	case 0: os << "2" << "C" << "[" << cd.pointValue << "]"; break;
	case 1: os << "2" << "H" << "[" << cd.pointValue << "]"; break;
	case 2: os << "2" << "S" << "[" << cd.pointValue << "]"; break;
	case 3: os << "2" << "D" << "[" << cd.pointValue << "]"; break;
	} break;
	case 2: switch (cd.cardSuit)
	{
	case 0: os << "3" << "C" << "[" << cd.pointValue << "]"; break;
	case 1: os << "3" << "H" << "[" << cd.pointValue << "]"; break;
	case 2: os << "3" << "S" << "[" << cd.pointValue << "]"; break;
	case 3: os << "3" << "D" << "[" << cd.pointValue << "]"; break;
	} break;
	case 3: switch (cd.cardSuit)
	{
	case 0: os << "4" << "C" << "[" << cd.pointValue << "]"; break;
	case 1: os << "4" << "H" << "[" << cd.pointValue << "]"; break;
	case 2: os << "4" << "S" << "[" << cd.pointValue << "]"; break;
	case 3: os << "4" << "D" << "[" << cd.pointValue << "]"; break;
	} break;
	case 4:switch (cd.cardSuit)
	{
	case 0: os << "5" << "C" << "[" << cd.pointValue << "]"; break;
	case 1: os << "5" << "H" << "[" << cd.pointValue << "]"; break;
	case 2: os << "5" << "S" << "[" << cd.pointValue << "]"; break;
	case 3: os << "5" << "D" << "[" << cd.pointValue << "]"; break;
	} break;
	case 5: switch (cd.cardSuit)
	{
	case 0: os << "6" << "C" << "[" << cd.pointValue << "]"; break;
	case 1: os << "6" << "H" << "[" << cd.pointValue << "]"; break;
	case 2: os << "6" << "S" << "[" << cd.pointValue << "]"; break;
	case 3: os << "6" << "D" << "[" << cd.pointValue << "]"; break;
	} break;
	case 6: switch (cd.cardSuit)
	{
	case 0: os << "7" << "C" << "[" << cd.pointValue << "]"; break;
	case 1: os << "7" << "H" << "[" << cd.pointValue << "]"; break;
	case 2: os << "7" << "S" << "[" << cd.pointValue << "]"; break;
	case 3: os << "7" << "D" << "[" << cd.pointValue << "]"; break;
	} break;
	case 7: switch (cd.cardSuit)
	{
	case 0: os << "8" << "C" << "[" << cd.pointValue << "]"; break;
	case 1: os << "8" << "H" << "[" << cd.pointValue << "]"; break;
	case 2: os << "8" << "S" << "[" << cd.pointValue << "]"; break;
	case 3: os << "8" << "D" << "[" << cd.pointValue << "]"; break;
	} break;
	case 8: switch (cd.cardSuit)
	{
	case 0: os << "9" << "C" << "[" << cd.pointValue << "]"; break;
	case 1: os << "9" << "H" << "[" << cd.pointValue << "]"; break;
	case 2: os << "9" << "S" << "[" << cd.pointValue << "]"; break;
	case 3: os << "9" << "D" << "[" << cd.pointValue << "]"; break;
	} break;
	case 9: switch (cd.cardSuit)
	{
	case 0: os << "10" << "C" << "[" << cd.pointValue << "]"; break;
	case 1: os << "10" << "H" << "[" << cd.pointValue << "]"; break;
	case 2: os << "10" << "S" << "[" << cd.pointValue << "]"; break;
	case 3: os << "10" << "D" << "[" << cd.pointValue << "]"; break;
	} break;
	case 10: switch (cd.cardSuit)
	{
	case 0: os << "J" << "C" << "[" << cd.pointValue << "]"; break;
	case 1: os << "J" << "H" << "[" << cd.pointValue << "]"; break;
	case 2: os << "J" << "S" << "[" << cd.pointValue << "]"; break;
	case 3: os << "J" << "D" << "[" << cd.pointValue << "]"; break;
	} break;
	case 11: switch (cd.cardSuit)
	{
	case 0: os << "Q" << "C" << "[" << cd.pointValue << "]"; break;
	case 1: os << "Q" << "H" << "[" << cd.pointValue << "]"; break;
	case 2: os << "Q" << "S" << "[" << cd.pointValue << "]"; break;
	case 3: os << "Q" << "D" << "[" << cd.pointValue << "]"; break;
	} break;
	case 12: switch (cd.cardSuit)
	{
	case 0: os << "K" << "C" << "[" << cd.pointValue << "]"; break;
	case 1: os << "K" << "H" << "[" << cd.pointValue << "]"; break;
	case 2: os << "K" << "S" << "[" << cd.pointValue << "]"; break;
	case 3: os << "K" << "D" << "[" << cd.pointValue << "]"; break;
	} break;
	}
	return os;
}

/*(3)(<_OVERLOAD)
 *	Purpose: Overloads the "less-than" operator(<), for use with the "Card" 
 *   class. Used for comparing card-point value ONLY						  */
bool Card::operator<(const Card& cd) const
{
	if (this->pointValue < cd.pointValue)
		return true;
	else
		return false;
}

/*(3)(>_OVERLOAD)
 *	Purpose: Overloads the "greater-than" operator(>), for use with the "Card" 
 *   class.	 Used for comparing card-point value ONLY						  */
bool Card::operator>(const Card& cd) const
{
	if (this->pointValue > cd.pointValue)
		return true;
	else
		return false;
}

/*(4)(==_OVERLOAD)
 *	Purpose: Overloads the equals operator(==), for use with the "Card" 
 *   class. Used for comparing card-point value ONLY						  */
bool Card::operator==(const Card& cd) const
{
	if (this->pointValue == cd.pointValue)
		return true;
	else
		return false;
}

/*(5)(GET_POINTVALUE)
 *	Purpose: Overloads the insertion operator(<<), for use with the "Card" 
 *   class. Initialized all card Face_Values.								  */
int Card::getPointValue() const
{
	return this->pointValue;
}

/*(6)(GET_FACEVALUE)
 *	Purpose: Returns the face value of the card: Ace: 0, 2: 1, 3:2, ....
 *  ... Queen:11, King:12.  												  */
int Card::getFaceValue() const
{
	return this->cardFace;
}

/*(7)(GET_SUIT)
 *	Purpose: Returns: The "enum" suit of the calling Card object			  */
suit Card::getSuit() const
{
	return this->cardSuit;
}
