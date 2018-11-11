/* Dylan Kapustka
   Fstream Practice
   Dr. Javaher
   11-11-2018
 */

//Pre-processor directive
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std; //Standard lib

//Main begins
int main()
{
	//fstream for input/output file
	fstream Sumy;
	
	//Delcaration of Variables
	int num;
	int sum = 0;
	int count = 0; // set to zero for valid count
	int average;
	double product = 1; // doulbe to prevent overflow, set to 1 to initialize and return correct answer

	//File open
	Sumy.open("numbers.txt");

	//If file is not open, program opens stating error. 
	if (!Sumy) 
	{
		cout << "There was an error opening the file" << endl;
		system("Pause");
		return 0;
	}

	//While file is being read
	while (Sumy >> num) //integers within file are extracted and stored as int num.
	{
		
		count++; //post-increment used to count up integers
		sum += num;  // addition assignment to find sum
		average = sum / count; //division assignment for average
		product *= num; //multiplication assignment for product
	}
	
	

	Sumy.clear(); //reset and allow further operations like output to be made on Sumy

	//Output to file

	Sumy << "\nThe Sum is: " << sum; //sum of numbers
	Sumy << "\nThe Average is: " << average; // average
	Sumy << "\nThe Product is: " << fixed << setprecision(2) << product; //fixed/setprecision used to prevent floating point answer

	Sumy.close(); //File close
}

//Fin