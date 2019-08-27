/* Michael Ziegler
 * CSCI 3110-001
 * Project #2
 * Due: 02/06/19
 * 
 * File: gaspump.h
 * Purpose: *INTERFACE* for the following program: n this assignment you will 
 * create a class representing a gasoline pump. The pump will maintain a
 * running total of the amount of fuel dispensed, and revenues collected. The 
 * DRIVER PROGRAM will simulate fuel demand for a number of vehicles.
 * 
 */
#include <iostream>
#include <string>

#ifndef GASPUMP_H
#define GASPUMP_H

class GasPump
{
	private: 
		std::string gasType;
		double fuelOnHand;
		double pumpCapacity;
		double pricePerGallon;
		double totalDispensed;
		double totalPurchases;
		bool turnAway;
		void replenish();
public:
		GasPump(std::string gasType, double pumpCapacity, double pricePerGallon);
		std::string getgasType(){return gasType;}
		double getpricePerGallon(){return pricePerGallon;}
		double getpumpCapacity(){return pumpCapacity;}
		double getfuelOnHand(){return fuelOnHand;}
		double getallDispensed(){return totalDispensed;}
		double getallPurchases(){return totalPurchases;}
		void dispenseFuel(double* darray, double purchaseAmount);
};
#endif
