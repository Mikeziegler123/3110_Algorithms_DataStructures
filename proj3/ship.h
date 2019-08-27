/* Michael Ziegler											     SHIP_BASE_CLASS
 * CSCI 3110-001
 * Project #3
 * Due: 02/19/19
 * 
 * File: ship.h
 * Purpose: *INTERFACE* for the following assignment: In this assignment you 
 * will create a class representing a ship, and two additional classes that 
 * inherit from the Ship class, a CargoShip class and a CruiseShip class. The 
 * project is geared toward giving you practical experience with characteristics
 * and C++ implementation details of inheritance and polymorphism. 
 * 
 */
#include <iostream>
#include <string>

#ifndef SHIP_H
#define SHIP_H

class Ship
{
	protected: 
		std::string shipName;
		double fuelLoad;
		
	public:
		Ship(std::string, double);
		void fuel();
		virtual void sail(){std::cout << shipName << " " << "sailing\n";}
		virtual void load(int) = 0; 
};
#endif

