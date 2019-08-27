/* Michael Ziegler											     CARGOSHIP_CLASS
 * CSCI 3110-001
 * Project #3
 * Due: 02/19/19
 * 
 * File: cargoship.h
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

#ifndef CARGOSHIP_H
#define CARGOSHIP_H

class CargoShip : public Ship
{
	private: 
		double* forwardTonnage;
		double* aftTonnage;
		int cargoCap;
		double forwardBayPer;
		
	public:
		CargoShip(std::string, double, int, double);			   //Constructor
		~CargoShip()										    	//Destructor
		{
			delete forwardTonnage;
			delete aftTonnage;
		}
		void fuel(int);
		void load(int) override;
};
#endif
