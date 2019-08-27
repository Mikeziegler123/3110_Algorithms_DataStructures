/* Michael Ziegler
 * CSCI 3110-001
 * Project #2
 * Due: 02/06/19
 * 
 * File: gaspump.cpp
 * Purpose: *IMPLIMENTATION* for the following program: n this assignment you will 
 * create a class representing a gasoline pump. The pump will maintain a
 * running total of the amount of fuel dispensed, and revenues collected. The 
 * DRIVER PROGRAM will simulate fuel demand for a
 * number of vehicles.
 * 
 */
#include "gaspump.h"
/*(1)(CONSTRUCTOR)
 *	Purpose: This function sets the value of 3 data members, and initializes the
 *  fuel quantity on hand to the maximum fuel capacity.                      */
GasPump::GasPump(std::string x, double y, double z)
{
	gasType = x;
	pumpCapacity = y;
	fuelOnHand = pumpCapacity;
	pricePerGallon = z;
}
/*(2)(DISPENSE_FUEL)
 *	Purpose:This function Controls the fueling of a single vehicle, setting the 
 *  values of a 2 element array, and ensuring that the amount of fuel a vehicle 
 *  recieves is not more than that pump it has available in it's tank.        */
void GasPump::dispenseFuel(double* darray, double purchaseAmount)
{
	//convert: purchase amount --> gallons of fuel
	double gallonsPumped = purchaseAmount/pricePerGallon;
	//check replenish(); turn customer away if replenishment is in progress
	if(turnAway == true)
	{
		//replenish tank
		replenish();
		//turn away customer
		gallonsPumped = 0.00;
		purchaseAmount = 0.00;
		//reopen pump for next customer
		turnAway = false;
	}
	//check fuelOnHand(); ensure pump dispenses no more than desired value.
	if((fuelOnHand <= gallonsPumped) && (turnAway == false))
	{
		gallonsPumped = fuelOnHand;
		purchaseAmount = fuelOnHand*pricePerGallon;
		//turn next customer away
		turnAway = true;
	}
	//aggregate: totalDispensed, fuelOnHand
	totalDispensed += gallonsPumped;
	fuelOnHand -= gallonsPumped;
	//aggregate: totalPurchases
	totalPurchases += purchaseAmount;
	//update: 2 element "darray"([0]Purchase amount, [1]Amount Dispensed)
	darray[0] = purchaseAmount;
	darray[1] = gallonsPumped;
}	
/*(3)REPLENISH
 *	Purpose: This function Resets the fuel 
 *  tank level to it's maximum capacity.                                      */
void GasPump::replenish()
{
	fuelOnHand = pumpCapacity;
}
