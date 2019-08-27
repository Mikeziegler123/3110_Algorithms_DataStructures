/* Michael Ziegler											 SHIP_IMPLIMENTATION
 * CSCI 3110-001
 * Project #3
 * Due: 02/19/19
 * 
 * File: ship.cpp
 * Purpose: *IMPLIMENTATION* for the following assignment: In this assignment you 
 * will create a class representing a ship, and two additional classes that 
 * inherit from the Ship class, a CargoShip class and a CruiseShip class. The 
 * project is geared toward giving you practical experience with characteristics
 * and C++ implementation details of inheritance and polymorphism. 
 * 
 */
#include "ship.h"

/*(1)(CONSTRUCTOR)
 *	Purpose: This function sets the value of 2 data members, and initializes the
 *  fuel load, and the ship's name.                      					  */
Ship::Ship(std::string x, double y)
{
	shipName = x;
	fuelLoad = y;
}
/*(FUEL)
 *	Purpose: This function prints out the ship's name, and fuel load. 	      */
void Ship::fuel()
{
	std::cout << shipName << " " << fuelLoad << "\n";
}
