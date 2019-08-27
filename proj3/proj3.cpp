/* Michael Ziegler                                                DRIVER_PROGRAM
 * CSCI 3110-001
 * Project #3
 * Due: 02/19/19
 * 
 * File: proj3.cpp
 * Purpose: *DRIVER_PROGRAM* for the following assignment:  In this assignment you 
 * will create a class representing a ship, and two additional classes that 
 * inherit from the Ship class, a CargoShip class and a CruiseShip class. The 
 * project is geared toward giving you practical experience with characteristics
 * and C++ implementation details of inheritance and polymorphism. 
 * 
 */
#include "cargoship.h"
#include "cruiseship.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

void sailShip(Ship &); 

int main()
{
	std::ifstream myin;
	myin.open("ships.txt");
	
	std::string cargoName, cruiseName;
	double cargoFuel, cruiseFuel;
	double cruiseLuxury, cruiseUpper, cruiseLower, cargoForward;
	int numPassengers, cargoCapacity, cargoTonnage, fuelFlashpoint;
	
	myin >> cruiseName >> cruiseFuel >> cruiseLuxury >> cruiseUpper >>
	cruiseLower >> numPassengers >> cargoName >> cargoFuel >> cargoCapacity >>
	cargoForward >> cargoTonnage >> fuelFlashpoint;
	
	CruiseShip myCruise(cruiseName, cruiseFuel, cruiseLuxury, cruiseUpper, cruiseLower);
	myCruise.fuel();
	myCruise.load(numPassengers);
	sailShip(myCruise);
	
	CargoShip myCargo(cargoName, cargoFuel, cargoCapacity, cargoForward);
	myCargo.fuel(fuelFlashpoint);
	myCargo.load(cargoTonnage);
	sailShip(myCargo);	 
	
	return 0;
}
/*(1)SAILSHIP
 *	Purpose: This function simulates the ship getting underway with a single 
 * function call invoked through the object, "sail".
 * Input(1): A reference to a ship object									  */
void sailShip(Ship & obj)
{
	obj.sail();
}
