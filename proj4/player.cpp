/* Michael Ziegler                                       PLAYER_IMPLIMENTATION
 * CSCI 3110-001
 * Project #4
 * Due: 02/28/19
 * 
 * File: player.cpp
 * Purpose: Player class implimentation for proj4 executable.
 */
#include "player.h"

/*(1)(CONSTRUCTOR)
 *	Purpose: Sets the player's name, and sets initial score to 0. The player's 
 *   name defaults to "unknown" if not supplied. Updates player's cards.      */
Player::Player(std::string n)
{
	name = n;
	score = 0;
	for (int i = 0; i < Max_Cards; i++)
	{
		hasPlayed[i] = true;
	}
}

/*(2)(PLAYCARD)
 *	Purpose: Simulates player removing one card from hand and playing it. 
 *  -> Returns the card with the highest point value, per specification rules.*/
Card Player::playCard()
{
	int index;
	int currentpHighestValue = hand[0].getPointValue();
	int currentfHighestValue = 0;
	int currentsLowestValue = 3;

	Card play;

	for (int i = 0; i < Max_Cards; i++) // Loop to analyze cards in hand
	{   //(1)is this card's point Value > the current highest point value(d:0)?
		if(hand[i].getPointValue() > currentpHighestValue)  				    //TIEBREAKER (1) - point
		{		//  Yes? --->  SET CURRENT PLAYED CARD:
						//Store Highest Point value.
						//Store index.
			index = i;
						//Store___Point_Value___.
			currentpHighestValue = hand[i].getPointValue();
		}
			    //  No? then,
		//(2)does this card's point value == the current highest point value(d:0)?
		else if(hand[i].getPointValue() == currentpHighestValue)
		{	    //Yes?
			//(*a*)is it's face Value > the current face value(d:-1)?
			if(hand[i].getFaceValue() > currentfHighestValue)				    //TIEBREAKER (2) - face
			{  //Yes?  --->  SET CURRENT PLAYED CARD TO:
						//Store index.
				index = i;
						//Store___Face_& Suit_ values.
				currentfHighestValue = hand[i].getFaceValue();
				currentsLowestValue = hand[i].getSuit();
			}
			//(*b*)does it's point value == the current highest point value(d:0)?
			 //AND, does it's face value == the current highest face value(d:-1)??
			else if(hand[i].getFaceValue() == currentfHighestValue)
			{	//is it's Suit value *LESS<THAN* the current lowest Suit value?
				if(hand[i].getSuit() < currentsLowestValue)				        //TIEBREAKER (3) - suit
				{   //Yes? --->  SET CURRENT PLAYED CARD:
						//Store Index.
					index = i;
						//Store_ Suit Value___.
				currentsLowestValue = hand[i].getSuit();
				}
			}
		}
	}
	//Set played card to current index(Highest card - in hand)
	play = hand[index]; 
	hand[index] = Card();
	hasPlayed[index] = true;
	return play;
}

/*(3)(DRAWCARD)
 *	Purpose: Draws the top card from the deck and replaces it with the most  
 *   recently played cards in the player's hand.     		                  */
void Player::drawCard(Deck& dk)
{
	if(hasPlayed[0] == true)
	{
		hand[0] = dk.dealCard();
		hasPlayed[0] = false;
	}
	else if(hasPlayed[1] == true)
	{
		hand[1] = dk.dealCard();
		hasPlayed[1] = false;
	}
	else if(hasPlayed[2] == true)
	{
		hand[2] = dk.dealCard(); 
		hasPlayed[2] = false;
	}
}

/*(4)(ADDSCORE)
 *	Purpose: Adds the point value of the winning card(s) to the player's score.
																			  */
void Player::addScore(Card acard)
{
	score += acard.getPointValue();
}

/*(5)(EMPTYHAND)
 *	Purpose: Checks to see if the player's hand is out of cards. Returns true if
 * the player's hand is out of cards, and false if cards are still available. */
bool Player::emptyHand() const
{
	if (hasPlayed[0] == true && hasPlayed[1] == true && hasPlayed[2] == true)
		return true;
	else
		return false;
}

/*(6)(<<_OVERLOAD)
 *	Purpose: Overloads the insertion operator(<<), for use with the "Player" 
 *   class. Prints out a blank "_____ ", for the card that has been played.   */
ostream& operator<< (std::ostream& os, const Player& plr)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (plr.hasPlayed[i] == true)
			os << "_____ ";
		else
			os << plr.hand[i] << " ";
	}
	os << "(" << plr.score << ")";

	return os;
}
