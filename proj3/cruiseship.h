/* Michael Ziegler										        CRUISESHIP_CLASS
 * CSCI 3110-001
 * Project #3
 * Due: 02/19/19
 * 
 * File: cruiseship.h
 * Purpose: *INTERFACE* for the following assignment: In this assignment you 
 * will create a class representing a ship, and two additional classes that 
 * inherit from the Ship class, a CargoShip class and a CruiseShip class. The 
 * project is geared toward giving you practical experience with characteristics
 * and C++ implementation details of inheritance and polymorphism. 
 * 
 */
#include <iostream>
#include <string>
#include "ship.h"

#ifndef CRUISESHIP_H
#define CRUISESHIP_H

class CruiseShip : public Ship
{
	private:
		double luxPer;
		double uDeckPer;		// upper deck percentage
		double lDeckPer;		// lower deck percentage
		int numPassLux;			// number of passengers in luxury
		int numPassUp;			// number of passengers in upper deck
		int numPassLow;			// number of passengers in lower deck
		
	public:
		CruiseShip(std::string, double, double, double, double);
		void sail();
		void load(int);
};
#endif
