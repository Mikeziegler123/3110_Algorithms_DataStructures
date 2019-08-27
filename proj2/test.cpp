#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class GasPump
{
	private: 
		string gasType;
		double fuelOnHand;
		double pumpCapacity;
		double pricePerGallon;
		double totalDispensed;
		double totalPurchases;
		bool turnAway;
		void replenish();
public:
		GasPump(string gasType, double pumpCapacity, double pricePerGallon);
		string getgasType(){return gasType;}
		double getpricePerGallon(){return pricePerGallon;}
		double getpumpCapacity(){return pumpCapacity;}
		double getfuelOnHand(){return fuelOnHand;}
		double getallDispensed(){return totalDispensed;}
		double getallPurchases(){return totalPurchases;}
		void dispenseFuel(double* darray, double purchaseAmount);
};

int main()
{
	ifstream myin;
	myin.open("gas.txt");
	
	string t1, t2, t3;
	int randomSeed, numVehicles;
	double pc1, pc2, pc3, ppg1, ppg2, ppg3, prct1, prct2, prct3;
	
	myin >> randomSeed >> numVehicles;
	
	myin >> t1 >> pc1 >> ppg1 >> prct1 
		 >> t2 >> pc2 >> ppg2 >> prct2
		 >> t3 >> pc3 >> ppg3 >> prct3; 
		 
	GasPump* array[3] = {new GasPump(t1, pc1, ppg1),
						 new GasPump(t2, pc2, ppg2),
						 new GasPump(t3, pc3, ppg3)};

	/*cout << "randomSeed: " << randomSeed << endl;
	cout << "numVehicles: " << numVehicles << endl;
	cout << "Pump 1: " << array[0]->getgasType() <<"  "<<\
	array[0]->getpumpCapacity() <<"  "<< array[0]->getpricePerGallon() << endl;
	cout << "Pump 2: " << array[1]->getgasType() <<"  "<<\
	array[1]->getpumpCapacity() <<"  "<< array[1]->getpricePerGallon() << endl;
	cout << "Pump 3: " << array[2]->getgasType() <<"  "<<\
	array[2]->getpumpCapacity() <<"  "<< array[2]->getpricePerGallon() << endl;
*/
	double darray[2];
	srand(randomSeed);
	for(int i=0;i<numVehicles;i++)
	{
		cout << i+1 << " ";						   	   //print: vehicle number
		double randomPercent = ((double) rand()+1)/RAND_MAX;
		//Compare with If Statements to stacked percentages
		//(UNLEADED) draw
		if(randomPercent >= 0.5)
		{
			int randInt = ((int) rand()%6*5+30);
			cout << array[0]->getgasType() << " " <<  //print: type 
			fixed << setprecision(2) <<
			array[0]->getpricePerGallon() << " ";     //print: price per gallon
			array[0]->dispenseFuel(darray, static_cast<double>(randInt));
			cout << fixed << setprecision(2) <<
			static_cast<double>(randInt) << " " << darray[0] << " " <<	
			darray[1] << " " << 					  //print: actual gal/pumped
			array[0]->getfuelOnHand() << "\n";		  //print: gallonsRemaining
		}
		//(MIDGRADE) draw
		else if(randomPercent >= 0.3)
		{
			int randInt = ((int) rand()%6*5+30);
			cout << array[1]->getgasType() << " " <<  //print: type 
			fixed << setprecision(2) <<
			array[1]->getpricePerGallon() << " ";     //print: price per gallon
			array[1]->dispenseFuel(darray, static_cast<double>(randInt)); 
			cout << fixed << setprecision(2) <<
			static_cast<double>(randInt) << " " << darray[1] << " " <<
			darray[1] << " " << 					  //print: actual gal/pumped
			array[1]->getfuelOnHand() << "\n";		  //print: gallonsRemaining
		}
		//(PREMIUM+) draw
		else
		{
			int randInt = ((int) rand()%6*5+30);
			cout << array[2]->getgasType() << " " <<  //print: type 
			fixed << setprecision(2) <<
			array[2]->getpricePerGallon() << " ";     //print: price per gallon
			array[2]->dispenseFuel(darray, static_cast<double>(randInt));  
			cout << fixed << setprecision(2) <<
			static_cast<double>(randInt) << " " << darray[0] << " " <<	 
			darray[1] << " " << 					  //print: actual gal/pumped
			array[2]->getfuelOnHand() << "\n";		  //print: gallonsRemaining
		}
	}
	//print final totals
	cout << array[0]->getgasType() << " " << array[0]->getallDispensed() <<
	" " << array[0]->getallPurchases() << "\n";
	cout << array[1]->getgasType() << " " << array[1]->getallDispensed() <<
	" " << array[1]->getallPurchases() << "\n";
	cout << array[2]->getgasType() << " " << array[2]->getallDispensed() <<
	" " << array[2]->getallPurchases() << "\n";
	
	myin.close();
return 0;
}

//CONSTRUCTOR
//	Purpose: Sets the value of 3 data members, and initializes the fuel quantity
//  on hand to the maximum fuel capacity.
GasPump::GasPump(string x, double y, double z)
{
	gasType = x;
	pumpCapacity = y;
	fuelOnHand = pumpCapacity;
	pricePerGallon = z;
}


//DISPENSE_FUEL
//	Purpose: Controls the fueling of a single vehicle. Sets the values in a 
//	two element array: 
// 1.)actual purchase amount(element 0), and the actual 
//  quantity of fuel being dispensed to the vehicle (element 1).
// 2.)This function ensures that the amount of fuel a vehicle recieves is not
//  more than that pump it has available in it's tank
				/*double array[2]; dispenseFuel(&X, &Y); */
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
	//cout << endl << "GPumped: " << gallonsPumped << endl;
	//cout << "Purchase: " << purchaseAmount << endl;
}	


//REPLENISH
//	Purpose: Resest the fuel tank level to maximum capacity.
void GasPump::replenish()
{
	fuelOnHand = pumpCapacity;
}
w
