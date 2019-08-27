/* Michael Ziegler                                                DRIVER_PROGRAM
 * CSCI 3110-001
 * Project #7
 * Due: 03/15/19
 * 
 * File: proj7.cpp
 * Purpose:
 */
 
#include <fstream>
#include <algorithm>
#include "priorityqueue.h"
using std::cout;

int main()
{
	// Import random seed from "pqseed.txt. 
	int rSeed;
	ifstream myin;
	myin.open("pqseed.txt");
	myin >> rSeed;
	// Min priority queue
	PriorityQueue <Card, MinHeap<Card> > minQueue;
	// Max priority queue
	PriorityQueue <Card, MaxHeap<Card> > maxQueue;
	
	// Array of 13 spades.
	Card spadesDeck[13];
	for (int i = 0; i <= 12; i++)
		spadesDeck[i] = Card(i+1, spades);
		
	// Array of 13 hearts
	Card heartsDeck[13];
	for (int j = 0; j <= 12; j++)
		heartsDeck[j] = Card(j+1, hearts);


	// Shuffle both spades and hearts array using random seed from "pqseed.txt.
	srand(rSeed);
	std::random_shuffle(std::begin(spadesDeck), std::end(spadesDeck)); // spadesDeck is an array name
	std::random_shuffle(std::begin(heartsDeck), std::end(heartsDeck)); // heartsDeck is an array name

	/*<<<---------------------------SPADES_DECK---------------------------->>>*/
	/*                             e n q u e u e                              
	 * Enqueues the 13 Spades cards (in order from array indices 0 through12) 
	 * into the max priority queue, displaying the heap’s contents after each 
	 * enqueue.                                                               */
	for (int i = 0; i <= 12; i++)
	{
		cout << "Enqueued " << spadesDeck[i];
		maxQueue.enqueue(spadesDeck[i]);
		maxQueue.print();
		cout << "\n";
	}
	cout << "\n";
	/*                             d e q u e u e                         	  
	 * Dequeues each card individually from the max priority queue until it is 
	 * empty - displays the heap’s contents after each dequeue.               */
	for (int i = 0; i <= 12; i++)
	{
		maxQueue.dequeue();
		maxQueue.print();
		cout << "\n";
	}
	cout << "Max Heap Empty.\n";
	cout << "\n";
	/*<<<---------------------------HEARTS_DECK---------------------------->>>*/
	/*                             e n q u e u e                              
     * Enqueues the 13 Hearts cards (in order from array indices 0 through12) 
	 * into the min priority queue, displaying the heap’s contents after each 
	 * enqueue.                                                               */ 
	for (int j= 0; j <= 12; j++)
	{
		cout << "Enqueued " << heartsDeck[j];
		minQueue.enqueue(heartsDeck[j]);
		minQueue.print();
		cout << "\n";
	}
	cout << "\n";
	/*                             d e q u e u e                         	  
	 * Dequeues each card individually from the min priority queue until it is
	 * empty - displays the heap’s contents after each dequeue. 			  */
	for (int j = 0; j <= 12; j++)
	{
		minQueue.dequeue();
		minQueue.print();
		cout << "\n";
	} 
	cout << "Min Heap Empty.\n";
	cout << "\n";
	
	return 0;
}
