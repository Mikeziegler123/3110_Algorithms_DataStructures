/* Michael Ziegler								        CARGOSHIP_IMPLIMENTATION
 * CSCI 3110-001
 * Project #3
 * Due: 02/19/19
 * 
 * File: cargoship.cpp
 * Purpose: *IMPLIMENTATION* for the following assignment: In this assignment you 
 * will create a class representing a ship, and two additional classes that 
 * inherit from the Ship class, a CargoShip class and a CruiseShip class. The 
 * project is geared toward giving you practical experience with characteristics
 * and C++ implementation details of inheritance and polymorphism. 
 * 
 */
#include "cargoship.h"

/*(1)(CONSTRUCTOR)
 *	Purpose: This function passes parameters to the base class constructor(Ship)
 * and dynamically allocates the memory to represent the cargo bays, initializing 
 * them to zero.               								  */
CargoShip::CargoShip(std::string shipN, double fuelL, int cargoC, double 
forwardBayP) : Ship(shipN, fuelL)
{
	cargoCap = cargoC;
	forwardBayPer = forwardBayP;
	forwardTonnage = new double(0);
	aftTonnage = new double(0);
}
/*(1)(FUEL)
 *	Purpose: This function calls the Base class fuel function, before printing 
 * the Ship's name and fuel flashpoint. Overloads the base class function.    */
void CargoShip::fuel(int flashpoint)
{
	Ship::fuel();
	std::cout << shipName << " " << flashpoint << "\n";
}
/*(1)(LOAD)
 *	Purpose: This function assures that the load weight does not exceed ship
 *  capacity, loads the ship, and prints the forward/aft load weight Tonnage. */
void CargoShip::load(int cargoTons)			//Overrides the base class function.
{
	if(cargoTons > cargoCap)
	{
		cargoTons = cargoCap;
	}
	*forwardTonnage = (cargoTons * forwardBayPer);
	*aftTonnage = (cargoTons * (1.00 - forwardBayPer));
	std::cout << shipName << " " << *forwardTonnage << " " << *aftTonnage << "\n";
} 
