/* Michael Ziegler                                                    CARD_CLASS
 * CSCI 3110-001
 * Project #7
 * Due: 03/15/19
 * File: card.h
 * Purpose: Card Class for proj7.cpp
 */
 
#ifndef CARD_H
#define CARD_H

#include <iostream>
using std::ostream;

// Enumerated type that represents the card suits
enum suit {clubs, hearts, spades, diamonds};

class Card
{
public:

    //default constructor - required
	Card();

    //constructor that takes a card's face value (an integer) and its suit
	Card (int face, suit st);

    // overload the << operator to display the card
    friend ostream& operator << (ostream& os, const Card& cd);

    // compare and return true if *this has a lesser point value than cd, false otherwise
	bool operator <= (const Card& cd) const;

    // compare and return true if *this has a larger point value than cd, false otherwise
	bool operator >= (const Card& cd) const;

    // compare and return true if *this has the same point value as cd, false otherwise
	bool operator== (const Card& cd) const;

private:
	suit	cardSuit;		// card's suit
	int     cardFace;		// card's face value
};
#endif

