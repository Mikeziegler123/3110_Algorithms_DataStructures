/* Michael Ziegler								       CRUISESHIP_IMPLIMENTATION
 * CSCI 3110-001
 * Project #3
 * Due: 02/19/19
 * 
 * File: cruiseship.cpp
 * Purpose: *IMPLIMENTATION* for the following assignment: In this assignment you 
 * will create a class representing a ship, and two additional classes that 
 * inherit from the Ship class, a CargoShip class and a CruiseShip class. The 
 * project is geared toward giving you practical experience with characteristics
 * and C++ implementation details of inheritance and polymorphism. 
 */
#include "cruiseship.h"

/*(1)(CONSTRUCTOR)
 *	Purpose: This function sets the value of 5 data members, passing the fuel 
 * load, and the ship's name to the base class("ship")'s constructor.         */
CruiseShip::CruiseShip(std::string shipN, double fuelL, double luxXP, double \
upXP, double lowXP) : Ship(shipN, fuelL)
{
	luxPer = luxXP;					// sets initial the luxury percentage
	uDeckPer = upXP;				// sets initial the lower deck percentage
	lDeckPer = lowXP;				// sets initial the upper deck percentage
}
/*(2)(SAIL)
 *	Purpose: This function prints to standard output the ship's name, follewed 
 * by the the amount of passengers in each section:  Luxury, Upper, & Lower.  */
void CruiseShip::sail()                         //Overrides the base class virtual function.
{
	std::cout << shipName << " " << numPassLux << " " << numPassUp << " " <<
	numPassLow << "\n";
}
/*(3)(LOAD)
 *	Purpose: This function takes in the number of passengers, and distributes 
the passengers to their respective sections using the percentages provided.   */
void CruiseShip::load(int numPassengers)        //Overrides the base class virtual function.
{
	numPassLux = (numPassengers * luxPer);
	numPassUp = (numPassengers * uDeckPer);
	numPassLow = (numPassengers * lDeckPer);
} 
