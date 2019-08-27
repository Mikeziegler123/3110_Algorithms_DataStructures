/* Michael Ziegler
 * CSCI 3110-001
 * Project #2
 * Due: 02/06/19
 * 
 * File: proj2.cpp
 * Purpose: *DRIVER_PROGRAM* for the following program: In this assignment you will 
 * create a class representing a gasoline pump. The pump will maintain a
 * running total of the amount of fuel dispensed, and revenues collected. The 
 * DRIVER PROGRAM will simulate fuel demand for a
 * number of vehicles.
 * 
 */
#include "gaspump.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

int main()
{
	std::ifstream myin;
	myin.open("gas.txt");
	
	std::cout << std::fixed;
	std::cout.precision(2);
	
	std::string t1, t2, t3;
	int randomSeed, numVehicles;
	double pc1, pc2, pc3, ppg1, ppg2, ppg3, prct1, prct2, prct3;
	
	myin >> randomSeed >> numVehicles;
	
	myin >> t1 >> pc1 >> ppg1 >> prct1 
		 >> t2 >> pc2 >> ppg2 >> prct2
		 >> t3 >> pc3 >> ppg3 >> prct3; 
		 
	GasPump* array[3] = {new GasPump(t1, pc1, ppg1),
						 new GasPump(t2, pc2, ppg2),
						 new GasPump(t3, pc3, ppg3)};
	double darray[2];
	srand(randomSeed);
	for(int i=0;i<numVehicles;i++)
	{
		std::cout << i+1 << " ";					  //print: vehicle number
		double randomPercent = ((double) rand()+1)/RAND_MAX;
		//Compare with If Statements to stacked percentages
		//(UNLEADED) draw
		if(randomPercent >= 0.5)
		{
			//(0)Generate random value between $30 & $55 (Gas purchase amount)
			int randInt = ((int) rand()%6*5+30);
			//(1)Print(Pre-Dispense Fuel) values
			std::cout << array[0]->getgasType() << " "//print: type 
			<< array[0]->getpricePerGallon() << " ";  //print: price per gallon
			//(2)Call: dispenseFuel()
			array[0]->dispenseFuel(darray, static_cast<double>(randInt));
			//(3)Print(Post-Dispense Fuel) values
			std::cout << static_cast<double>(randInt) << " " << darray[0] << " " 	
			<< darray[1] << " " << 				      //print: actual gal/pumped
			array[0]->getfuelOnHand() << "\n";		  //print: gallonsRemaining
		}
		//(MIDGRADE) draw
		else if(randomPercent >= 0.3)
		{
			//(0)Generate random value between $30 & $55 (Gas purchase amount)
			int randInt = ((int) rand()%6*5+30);
			//(1)Print(Pre-Dispense Fuel) values
			std::cout << array[1]->getgasType() << " "//print: type 
			<< array[1]->getpricePerGallon() << " ";  //print: price per gallon
			//(2)Call: dispenseFuel()
			array[1]->dispenseFuel(darray, static_cast<double>(randInt)); 
			//(3)Print(Post-Dispense Fuel) values
			std::cout << static_cast<double>(randInt) << " " << darray[1] << " "
			<< darray[1] << " " << 			          //print: actual gal/pumped
			array[1]->getfuelOnHand() << "\n";		  //print: gallonsRemaining
		}
		//(PREMIUM+) draw
		else
		{
			//(0)Generate random value between $30 & $55 (Gas purchase amount)
			int randInt = ((int) rand()%6*5+30);
			//(1)Print(Pre-Dispense Fuel) values
			std::cout << array[2]->getgasType() << " "//print: type 
			<< array[2]->getpricePerGallon() << " ";  //print: price per gallon
			//(2)Call: dispenseFuel()
			array[2]->dispenseFuel(darray, static_cast<double>(randInt));  
			//(3)Print(Post-Dispense Fuel) values
			std::cout << static_cast<double>(randInt) << " " << darray[0] << " "
			<< darray[1] << " " << 				      //print: actual gal/pumped
			array[2]->getfuelOnHand() << "\n";		  //print: gallonsRemaining
		}
	}
	//print final totals
	std::cout << array[0]->getgasType() << " " << array[0]->getallDispensed() <<
	" " << array[0]->getallPurchases() << "\n";
	std::cout << array[1]->getgasType() << " " << array[1]->getallDispensed() <<
	" " << array[1]->getallPurchases() << "\n";
	std::cout << array[2]->getgasType() << " " << array[2]->getallDispensed() <<
	" " << array[2]->getallPurchases() << "\n";
	
	myin.close();
	
	//Delete dynamically allocated gas pumps
	delete array[0];
	delete array[1];
	delete array[2];
return 0;
}
