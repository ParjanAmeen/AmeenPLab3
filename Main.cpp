//----------------------------------------------------------------------------------------------------------------------
//Lab 3 Grading Block
//Name: Parjan Ameen 
//Lab Grade: 
//----------------------------------------------------------------------------------------------------------------------
//Total Possible Points -------------------------------------------------------------------------------------------> 200
//Total Points lost ----------------------------------------------------------------------------------------------->
//Lab Grade -------------------------------------------------------------------------------------------------------> 
//----------------------------------------------------------------------------------------------------------------------
//General Comments:
//  
//  
//  
//  
//----------------------------------------------------------------------------------------------------------------------
//Standard Requirements
//  Requirements met as specified for the
//  Which includes but not limited to:
//    Program Creation
//    File Requirements
//    Documentation
//    Documentation as required for Class Objects
//    Constants
//    Variables 
//    Code
//Comments:
//  
//  
//  
//Points Lost ----------------------------------------------------------------------------------------------------->
//
//Program Specifications
//-Standards.h included with the preprocessor directives
//-Course Required header & CPP file
//Comments:
//
//Points Lost ----------------------------------------------------------------------------------------------------->
//
//
//-integerClassType
//  Meets specs of the UML
//  Methods correctly named, defined, & created in header & CPP File, friends included
//  Constructor & Destructor included
//Comments:
//
//
//
//
//
//
//
//Points Lost ----------------------------------------------------------------------------------------------------->

//----------------------------------------------------------------------------------------------------------------------
//
//Main
// 3 objects instantiated, list positiveList, negativeList
// Input & Output files opened, precision set
// Course heading printed to screen & output file
// 1. list object created with data from the input file
// input file closed
// 2. Output the list with a heading formatted in columns as shown in the instructions
//    Output the count of numbers in the list
// 3. Output the position of a number as shown formatted in the instructions, testing with -1, 0, 39, 46
// 4. Find the smallest & largest values in the list
//    Output the smallest & largest with a heading formatted as shown in the instructions
//    If the list is empty, output a message that no values were found for both smallest & largest
// 5. Find an number in the list, testing with 98999 & 17
//    Output the number & the position found for each test value or a not found message
// 6. Calculate the sum & average of the list
//    Output the sum & average with a heading formatted as shown in the instructions
// 7. Create a positive & negative list from the original list if the list is not empty
//    0 is not included in either the positive or negative list
//    Output the positive list with a heading formatted as shown in the instructions
//    Output the negative list with a heading formatted as shown in the instructions
// 8. Print a list of numbers by the digits counts from 1 to largest number of digits in the list
// Close the input & output files
//Comment:
//
//
//
//
//Points Lost ----------------------------------------------------------------------------------------------------->
//----------------------------------------------------------------------------------------------------------------------

#include "Standards.h"
#include "IntegerClassType.h"

int main(void)
{
	//Instantiate an object of the type IntegerClassType for the entire list
	IntegerClassType list;

	//Instantiate an object of the type IntegerClassType for the positive numbers
	IntegerClassType posList;

	//Instantiate an object of the type IntegerClassType for the negative numbers
	IntegerClassType negList;
	
	//declare int variables
	int numbersInListCount = 0;
	int smallestNum = 0;
	int largestNum = 0;
	int sum = 0;
	int searchNumber = 0;
	int position = 0;

	//declare bool variables
	bool found = false;

	//declare double variables
	double average = 0;
	
	//declare file variables
	ofstream fout;
	ifstream fin;
	
	//Initial set up of program & List--------------------------------------------------------------
	//  
	//Open the two files
	fin.open("Numbers.txt");
	fout.open("Results.txt");
	
	//Set up fixed point output for the file
	fout << fixed << setprecision(2);
	
	//Output the course required header and file messages to the screen & the output file
	PrintFileName(static_cast<ofstream&> (cout), "Input", "Numbers.txt");

	//Call to output the output file names to the output file
	PrintFileName(static_cast<ofstream&> (cout), "Output", "Results.txt");

	//Call to output the course heading to the screen
	OutputHeading(static_cast<ofstream&> (cout));

	//Call to output the course heading to the output file
	OutputHeading(fout);

	//Fill the linked list with the numbers from the input file
	list.FillList(fin);
	
	//Close the input file
	fin.close();
	
	//Clear the input file flags
	fin.clear();

	//End of Initial set up of a program & list-----------------------------------------------------

	//Output of the Linked List read in-------------------------------------------------------------

	//Output the heading for the original link list to the output file
	list.PrintHeaderForOriginalList(fout);

	//Output the list to the output file
	list.PrintList(fout);

	//Set the count for the numbers in the list equal to the get
	numbersInListCount = list.GetCountOfNumbersInList();
	
	//Output to number of nodes in the original list to the output file
	list.PrintCountOfNumbersInList(fout, numbersInListCount);
	
	//End of Output of Linked List read in----------------------------------------------------------

	//List Print a node value in a position---------------------------------------------------------

	//Header for the print number in a position
	list.PrintHeaderForNumberInAPosition(fout);

	//Try to output the element at -1 position
	list.PrintNumberInAPosition(fout, -1);
	
	//Output the divider to the output file
	
	//Output the element at 0 position to the output file
	list.PrintNumberInAPosition(fout, 0);
	
	//Output the divider to the output file
	
	//Output the element at 39 position to the output file
	list.PrintNumberInAPosition(fout, 39);
	
	//Output the divider to the output file
	
	//Output the element at 46 position to the output file
	list.PrintNumberInAPosition(fout, 46);
	
	//Output the divider to the output file
	OutputDivider(fout, SYMBOL, WIDTH);
	
	//End of List print of a node value in a position-----------------------------------------------


	//Smallest & Largest values in a list-----------------------------------------------------------

	//Print the header
	list.PrintHeaderForSmallestAndLargest(fout);

	//Determine smallest & smallest message based on the start pointer
	smallestNum = list.FindSmallest();

	//Print the smallest number to the output file
	fout << "Smallest value is " << smallestNum << endl;

	//Call the PrintPositionOfNumber
	list.PrintPositionOfNumber(fout, smallestNum);
		
	//Output the divider to the output file
	OutputDivider(fout, SYMBOL, WIDTH);
	
	//Determine the largest & largest message based on the start of the list
	largestNum = list.FindLargest();

	//Print the largest number to the output file
	fout << "Largest value is " << largestNum << endl;

	//Call the PrintPositionOfNumber
	list.PrintPositionOfNumber(fout, largestNum);

	//Output the divider to the output file
	OutputDivider(fout, SYMBOL, WIDTH);
	
	//Create a header
	list.PrintHeaderForFindingNumbersInList(fout);

	//Set aNumber to a number not in the linked list
	searchNumber = 98999;
	
	//Find the number in the linked list
	list.FindNumberInList(searchNumber, position, found);
	
	//Determine message based on found
	fout << "The number " << searchNumber << " was NOT found in the linked list" << endl;
	
	//Set aNumber to a number in the linked list, 17
	searchNumber = 17;
	
	//Find the position of the number in the linked list
	list.FindNumberInList(searchNumber, position, found);
	
	//Determine message to output based on found
	fout << "The number " << searchNumber << " was found in position " << position << " in the linked list" << endl;

	//Sum & Average of the Linked List--------------------------------------------------------------

	//Call the print for the header of this section
	list.PrintHeaderSumAndAverage(fout);

	//Calculate the sum of all numbers in the linked list
	sum = list.CalculateSum();
	
	//Output the sum of the list of numbers to the output file
	fout << "The sum of all the numbers in the list is " << sum << endl;
	
	//Calculate the average of all numbers in the linked list
	average = list.CalculateAverage();
	
	//Output the average of the list of numbers to the output file, displaying 2 decimals
	fout << "The average of all the numbers in the list " << average << endl;
	
	//Output the divider to the output file
	OutputDivider(fout, SYMBOL, WIDTH);

	list.PrintByDigitCount(fout);

	//Fill the list again with the input data-------------------------------------------------------

	//Open the input file again
	fin.open("Numbers.txt");

	//Re - Fill the linked list with the data
	posList.PositiveList(fin);

	//End Fill the list again with the input data---------------------------------------------------
	fin.close();

	//Clear the input
	fin.clear();

	//Open the input file again
	fin.open("Numbers.txt");

	//Fill the negative list 
	negList.NegativeList(fin);

	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

	//Print the centered header
	PrintCenteredMessage(fout, "The Positive Linked list");

	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

	//Print the positive list
	posList.PrintList(fout);

	//Set the count for the numbers in the list equal to the get
	numbersInListCount = posList.GetCountOfNumbersInList();

	//Output to number of nodes in the positive list to the output file
	posList.PrintCountOfNumbersInList(fout, numbersInListCount);

	//Print the centered header
	PrintCenteredMessage(fout, "The Negative Linked list");

	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

	//Print the positive list
	negList.PrintList(fout);

	//Set the count for the numbers in the list equal to the get
	numbersInListCount = negList.GetCountOfNumbersInList();

	//Output to number of nodes in the positive list to the output file
	negList.PrintCountOfNumbersInList(fout, numbersInListCount);

	//Close the files
	fin.close();
	fout.close();

	return 0;
}