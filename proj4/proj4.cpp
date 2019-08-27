/* Author: Michael Ziegler
 * CSCI 3110-001
 * Project #4
 * Due: 02/28/19
 * 
 * File: proj4.cpp
 * Purpose: Write a C++ program to simulate a simple card game between two 
 * players. The 52 cards in a deck of cards are shuffled and each player draws
 * three cards from the top of the deck. Remaining cards are placed in a pile 
 * face-down between the two players. Players then select a card from the three
 * in their hand. The player playing the card with the highest point value wins,
 * and collects both cards and adds them to their pile (score). If the cards
 * played have the same point value, the hand is a draw (tie) and no points are 
 * accumulated by either player. At the completion of a hand, each player draws
 * the top card from the deck to add to their hand (player 1 first, then player
 * 2). Play continues until all cards have been played. The winner is the 
 * player with the most points at the game's end.
 * The deck is standard, with 52 cards, where the there are thirteen cards from 
 * each of four suits: hearts, spades, diamonds, and clubs. The thirteen cards 
 * in point order are the 2-10 numbered cards, the face cards ( Jack, Queen, 
 * King), and the Ace card. Points are distributed as follows: Ace=15, face 
 * cards=10, all other cards count as their numeric value.
 */
#include <fstream>
#include "player.h"

void simulateHand(Player&, Player&, Deck&);

int main()
{
	int rseed;
	std::string p1Name, p2Name;
	std::ifstream myin;
	
	/*Read in data from "cardgame.txt" input file. 							  */
	myin.open("cardgame.txt");
	myin >> p1Name >> p2Name >> rseed;
	
	/*Initializations from "cardgame.txt" input file. 						  */
	srand(rseed);
	Player One = Player(p1Name);
	Player Two = Player(p2Name);
	Deck Deck;
	
	std::cout << Deck << std::endl;
	Deck.Shuffle();
	
	std::cout << Deck << std::endl;

	One.drawCard(Deck);
	Two.drawCard(Deck);
	One.drawCard(Deck);
	Two.drawCard(Deck);
	One.drawCard(Deck);
	Two.drawCard(Deck);

	int hand = 1;
	while (!(One.emptyHand() && Two.emptyHand()))
	{
		simulateHand(One, Two, Deck);
		hand++;
	}
	std::cout << std::endl;
	if (One.getScore() > Two.getScore())
		std::cout << hand << "). " << One.getName() << "* " << One.getScore() << std::endl;
	else if (Two.getScore() > One.getScore())
		std::cout << hand << "). " << Two.getName() << "* " << Two.getScore() << std::endl;
	else 
		std::cout << "The game has ended in a draw with a score of " << One.getScore() << std::endl;

	return 0;
}

void simulateHand(Player& One, Player& Two, Deck& Deck)
{
	Card onePlay;
	Card twoPlay;

	std::cout << One;
	std::cout << Two << std::endl;
	onePlay = One.playCard();
	twoPlay = Two.playCard();
	//std::cout << One.getName() << onePlay << " --- " << Two.getName() << twoPlay << std::endl << std::endl; 
	if (onePlay > twoPlay)
	{
		std::cout << One.getName() << "* " << std::endl;
		One.addScore(onePlay);
		One.addScore(twoPlay);
	}
	else if (onePlay < twoPlay)
	{
		std::cout << Two.getName() << "* " << std::endl;
		Two.addScore(onePlay);
		Two.addScore(twoPlay);
	}
	else if(onePlay == twoPlay)
	{
		std::cout << " " << std::endl;
	}
	std::cout << One;
	std::cout << Two << std::endl;
	if (!Deck.isEmpty())
	{
		One.drawCard(Deck);
		Two.drawCard(Deck);
	}
	return;
}
