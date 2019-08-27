/* Michael Ziegler                                 PRIORITY_QUEUE_CLASS_TEMPLATE
 * CSCI 3110-001
 * Project #7
 * Due: 03/15/19
 * File: priorityqueue.h
 * Purpose: Priority_Queue Class template for proj7.cpp. This class represents a
 * priority queue implemented as a binary heap.
 * 		It has two type parameters:
 *			1) The type of the element stored in the heap. 
 *			2) A comparator class type.
 */ 
 
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include "card.h"
using namespace std;

template <typename elementType, typename Comparator>

class PriorityQueue
{
	
/*----------------------------<_P_u_b_l_i_c_>---------------------------------*/
public:

	/*(1)(CONSTRUCTOR)
	 *	Purpose: Resize the vector representing the heap to hold 50 items.    */
	PriorityQueue()
	{
		heapAr.resize(50);
	}

	// returns highest priority item in the heap
	int top(elementType index)
	{
		// return root
		int parent = (index - 1) / 2;

		return heapAr[parent];
	}
	
	/*(2)(DEQUEUE)
	 *  Purpose: Removes the highest priority item in the heap.				  */
	void dequeue()
	{
		if( !empty() )
			cout << "Dequeued " << heapAr[0];
		
		//replace parent with last child in heap
		// removes the last element in vector
		heapAr[0] = heapAr[size - 1];

		// reduce the container size by one
		size--;

		heapDown(0);

	}

	/*(3)(ENQUEUE)
	 *  Purpose: Takes one parameter: the item to be enqueued. Enqueues the item
	 *  and places it inthe proper heap order                                 */
	void enqueue(elementType item)
	{
		// insert item at size
		// put the item at the end of the heap
			heapAr[size] = item;
			size++;

			heapUp(size - 1);
	}
	
	/*(4)(EMPTY)
	 *Purpose: Returns true if queue is empty, and false otherwise.			  */          
	bool empty()
	{
			if (size == 0)
				return true;
			else
				return false;
	}
	/*(5)(PRINT)
	 * Purpose: Displays the items in the heap, from index 0 through number of
	 * elements minus 1.                                                      */
	void print()
	{
		if ( empty() )
			return;
		else
			for (int i = 0; i < size; i++)
				cout << heapAr[i];
	}	
	
/*---------------------------<_P_r_i_v_a_t_e_>--------------------------------*/ 
private:

	vector<elementType> heapAr;
	Comparator cmp;
	
	int size = 0;
	
	/*(6)(HEAPUP)
	 * Purpose: (private, void)  Takes an index parameter and heaps item up
	 * based on its priority.												  */
	void heapUp(int index)
	{
		// parent
		int parent = (index - 1) / 2;
	
		// base case
		if (index == 0 || cmp.HighPriority(heapAr[parent], heapAr[index]))
			return;
		
		// while element is not the parent and the index is >= to the 
		//parent's element:
		//	(1)Swap the element with its parent.
		// 	(2)Call the  recursive function.
		if (cmp.HighPriority(heapAr[index], heapAr[parent]))
		{
			elementType temp = heapAr[parent];
			heapAr[parent] = heapAr[index];
			heapAr[index] = temp;

			heapUp(parent);
		}

	}
	
	/*(7)(HEAPDOWN)
	 * Purpose: (private, void)  Takes an index parameter and heaps item down
	 * based on its priority.												  */				 
	void heapDown(int index)
	{
		int left_child = (index * 2) + 1;
		int right_child = (index * 2) + 2;
		
		// base case
		if (left_child > size)
			return;

		int largest = index;
		// check if the left child is the largest
		if (cmp.HighPriority(heapAr[left_child], heapAr[index]))
			largest = left_child;

		// check if the right child is the largest
		if (right_child < size && (cmp.HighPriority(heapAr[right_child], heapAr[largest])))
			largest = right_child;

		// swap
		if (largest != index)
		{
			elementType temp = heapAr[index];
			heapAr[index] = heapAr[largest];
			heapAr[largest] = temp;

			heapDown(largest);
		}
	}
};
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


/*---------<_C_o_m_p_a_r_a_t_o_r_-_C_l_a_s_s_-_T_e_m_p_l_a_t_e_s_>------------*/ 
/* e
 * (SPEC.): There will be two class template comparators each of which takes a 
 * type parameter. One of the comparators is used to compare if items are less 
 * than or equal to (<=), and the other to compare if they’re greater than or
 * equal to (>=). Each of these classes will have a single, public, bool 
 * function that returns the result of the above comparisons for two objects of 
 * the same type. This function must have the same name in both class templates.
 * These classes will be used in the declaration of the priority queues (i.e.,as
 * type parameters), and will be defined in the file priorityqueue.h, outside of
 * the PriorityQueue class template. The handout (Fig 1.24) on the course 
 * calendar is an example of a custom comparator class. This example must be 
 * converted to a class template so that it can be used with any custom class 
 * (i.e. so that it does not compare only strings). 
 */

/* (*8*)(COMPARATOR_<=_)
 *  Purpose: To determine if the Highest Priority item is less than or equal to 
 * the item being compared.							                  */
template <typename elementType>

class MinHeap
{
/*----------------------------<_P_u_b_l_i_c_>---------------------------------*/
public:
	bool HighPriority(const elementType &lhs, const elementType &rhs) const
	{
		return (lhs <= rhs);
	}
};

/* (*9*)(COMPARATOR_>=_)
 *  Purpose: To determine if the Highest Priority item is greater than or equal
 * to (>=), the item being compared.						                  */
template <typename elementType>

class MaxHeap
{
/*----------------------------<_P_u_b_l_i_c_>---------------------------------*/

public:
	bool HighPriority(const elementType &lhs, const elementType &rhs) const
	{
		return (lhs >= rhs);
	}
};

#endif
