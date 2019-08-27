/* Michael Ziegler                                                  PLAYER_CLASS
 * CSCI 3110-001
 * Project #4
 * Due: 02/28/19
 * File: player.h
 * Purpose: Player Class for proj4.cpp
 */
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "deck.h"
#include "card.h"

using std::ostream;
using std::string;

class Player
{
public:
    static const int Max_Cards = 3; // # of cards a player can have in a hand

    // constructor - player's name defaults to "unknown" if not supplied
	Player(string name="unknown");

    // Simulates player removing one card from hand and playing it - returns the card
	// Play the card with the highest value, per the rules in the specification 
	Card playCard();

    // draw top card from the deck to replace played card in hand
	void drawCard(Deck& dk);

    // add the point value of the card to the player's score
	void addScore(Card acard);

    // return the score the player has earned so far
	int getScore() const{return score;}

    // return the name of the player
    std::string getName() const{return name;}

    // return true if the player's hand is out of cards
	bool emptyHand() const;

    // overload the << operator to display cards in player's hand (or _____ if no card)
    friend std::ostream& operator << (std::ostream&, const Player&);
	
private:
	string  name;					// the player's name
	int     score;					// the player's score
	Card    hand[Max_Cards];		// array holding the cards currently in the player's hand
	bool    hasPlayed[Max_Cards];	// hasPlayed[i] indicates that hand[i] (i.e., ith card in player's hand)
									// has been played
};

#endif


