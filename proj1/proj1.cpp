/* Author: Michael Ziegler
 * CSCI 3110-001
 * Project #1
 * Due: 01/28/19
 * 
 * Purpose: This program utilizes a Dynamic Array to read in a list of numbers
 * from file "nums.txt". Before beginning to read in the numbers, the program 
 * prompts the user to input a number, the size of the initial array between 
 * 100 and 350 per specification (to avoid error). As the program reads in from
 * the list, if the amount of numbers exceeds the current working size of the 
 * array, the program will reallocate more space at the expansion rate of 25% 
 * for each necessary array expansion. Lastly, the program, using standard 
 * output, will display the initial working array size, followed by a reading 
 *  for each time the array reached it's working size limit, and was expanded. 
 *  Each time this occu
 * rs, the program will display the current array capacity, 
 * as it is met, and the cumulative average of the numbers being read at that 
 * time. The final number of the output will show the total average of all the
 * numbers in "nums.txt". 
 */
 
#include <iostream>
#include <fstream>
using namespace std;

int* allocateArray(int *array, int *arraySize, double expansionRate);
double calcAverage(int *array, int numOfValues);
/* MAIN FUNCTION
 * Purpose: Dynamically Allocated Array / Average per variable rate of change */
int main()
{
	int arraySize, hold;
	float expansionRate;
	
	ifstream inputFile;
	inputFile.open("nums.txt");

	ofstream outputFile;
	outputFile.open("out.txt");
	
	inputFile >> arraySize;
	cout << arraySize << "\n";
	outputFile << arraySize << "\n";

	if(((arraySize%50)!=0) || arraySize > 350 || arraySize < 100)
	{
		cout <<"Error";
		exit(1);
	}
	int* array = nullptr;
	inputFile >> expansionRate;
	array = allocateArray(array, &arraySize, expansionRate);
	cout << arraySize;
	outputFile << arraySize;

	int value = 0;
	int counter = 0;
	double avg = 0;

	while(inputFile >> value)
    {
        *(array + counter) = value;
        if((counter == arraySize - 1))
        {
            avg = calcAverage(array, counter+1);
            array = allocateArray(array, &arraySize, expansionRate);
            cout << " " << avg << "\n" << arraySize;
			outputFile << " " << avg << "\n" << arraySize;
        }
        counter++;
    }
    avg = calcAverage(array, counter);
    cout << " " << counter << " " << avg << "\n";
    outputFile<< " " << counter << " " << avg << "\n";
    inputFile.close();
    outputFile.close();
    delete [] array;
    
    return 0;
    }//endMain
    //FUNCTION DEFINITIONS
	/*(1) allocateArray 
	 * Purpose: To expand the array upon reaching capacity. Return: Ptr-->Arr */ 
    int* allocateArray(int *oldArray, int *arraySize, double expansionRate)
    {
        int *newArray;
        if(oldArray == nullptr)
        {
            newArray = new int[*arraySize];
        }
        else
        {
            int newSize;
            {
                newSize = *arraySize * (expansionRate + 1);
            }
            newArray = new int[newSize];
            for(int i=0;i<*arraySize;i++)
            {
                *(newArray+i) = *(oldArray+i);
            }
            *arraySize = newSize;
        }
        delete[] oldArray;
        return newArray;
    }
    /*(2) calcAverage
	 * Purpose: To periodically calculate the input average. Return: Double   */
	double calcAverage(int *array, int numOfValues)
    {
        double sum = 0;
        double avg;
        for(int i = 0;i<numOfValues;i++)
            sum += array[i];
        avg = sum/numOfValues;
        return avg;
    }
