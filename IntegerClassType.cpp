///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Programmer's Name: Parjan Ameen
// File Name:         IntegerClassType.h
// Associated File:   IntegerClassType.cpp                                                                                           
// CPP File Contains:
//Contains Gets, Sets, prints, and other functions for the IntegerClassType
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "IntegerClassType.h"

//----------------------------------------------------------------------------------------------------------------------
//CreateList - Creates an empty linked list
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::CreateList(void)
{
	//Creates an empty list
	start = NULL;
}

//----------------------------------------------------------------------------------------------------------------------
//IsEmpty - Tests to see if the list is empty, if start of list is null
//----------------------------------------------------------------------------------------------------------------------
bool IntegerClassType::IsEmpty(void)
{
	return (start == NULL);
}

//----------------------------------------------------------------------------------------------------------------------
//FreeTheList - Frees the memory for all the nodes remaining in the linked list
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::FreeTheList(void)
{
	nodePtr aNode;

	//While there are nodes in the linked list
	while (!IsEmpty()) 
	{
		//Assign ANode a value - Set node to the first item in the list
		aNode = start;

		//Assign start a value - Move start to the next node
		start = start->link;

		//Assign aNode's link a value - Sever pointer from the list
		aNode->link = NULL;

		//Reset the count of numbers in the list to zero
		countOfNumberList = 0;

		//Free the memory for this pointer
		delete aNode;
	}
}

//----------------------------------------------------------------------------------------------------------------------
//SetCountOfDigits - Finds the number of digits in a number passed in
//----------------------------------------------------------------------------------------------------------------------
int IntegerClassType::SetCountOfDigits(int aNumber)
{
	//Local variables
	int counter = 0;

	//Determine if the number is a zero
	if (aNumber == 0)
	{
		//Set the counter equal to one
		counter = 1;
	}

	//While the number does not equal zero
	else
	{
		//Take the absolute value of the number
		aNumber = abs(aNumber);

		while (aNumber != 0)
		{
			//Divide the number passed in by 10 to reduce it
			aNumber = aNumber / 10;

			//Increment the digit counter
			counter++;
		}

	}

	return counter;
}

//----------------------------------------------------------------------------------------------------------------------
//FindPtrAtEndOfList - Find the pointer at the end of the linked list which is then returned
//----------------------------------------------------------------------------------------------------------------------
nodePtr IntegerClassType::FindPtrAtEndOfList()
{
	//Local variables
	nodePtr current;
	nodePtr previous;

	//Assigning values for the local variables
	current = start;
	previous = NULL;

	while (current != NULL)
	{											
		//Moving the pointers along
		previous = current;
		current = current->link;

	}
	
	//Return the pointer
	return previous;
}

//----------------------------------------------------------------------------------------------------------------------
//GetCountOfNumbersInList - Returns the count of the number of items in the list
//----------------------------------------------------------------------------------------------------------------------
int IntegerClassType::GetCountOfNumbersInList()
{
	//Local variables
	nodePtr temp;

	//Initialize the count of numbers in the list
	countOfNumberList = 0;

	//Set the temp equal to the start
	temp = start;

	while (temp != NULL)
	{
		//Increment the count of numbers in the list
		countOfNumberList++;

		//Move to the next pointer
		temp = temp->link;
	}

	return countOfNumberList;
}

//----------------------------------------------------------------------------------------------------------------------
//CreateANode - Creates a new memory for the node and sets the new number for the data
//----------------------------------------------------------------------------------------------------------------------
nodePtr IntegerClassType::CreateANode(int aNumber)
{
	//Create a node to set the ptr to the address of this node
	nodePtr ptr = new node;

	//Assign the number a value
	ptr->data.number = aNumber;

	//Call the SetCountOfDigits
	ptr->data.countOfDigits = SetCountOfDigits(aNumber);

	//Set the link to NULL
	ptr->link = NULL;

	return ptr;
}

//----------------------------------------------------------------------------------------------------------------------
//FindLargestDigitCount - Finds the number which has the largest count of digits in the list
//----------------------------------------------------------------------------------------------------------------------
int IntegerClassType::FindLargestDigitCount()
{
	//Local variables
	int highestDigitCount = -1;
	nodePtr temp;

	//Set the temp equal to the start
	temp = start;

	while (temp != NULL)
	{													
		if (highestDigitCount < temp->data.countOfDigits)
		{
			//Assign the highest digit count of the number passed in
			highestDigitCount = temp->data.countOfDigits;
		}

		//Move to the next pointer
		temp = temp->link;
	}
	
	return highestDigitCount;

}

//----------------------------------------------------------------------------------------------------------------------
//AddToList - Adds a node to the end of the linked list
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::AddToList(nodePtr ptr)
{
	//Local variable 
	nodePtr insertPtr;

	if (IsEmpty())
	{
		//Set the start pointer equal to the pointer from the parameter
		start = ptr;
	}
	
	else
	{
		//Find the insertion point at the end of the list
		insertPtr = FindPtrAtEndOfList();

		//Determine linking based on pointer position for insertion
		if (insertPtr == NULL)
		{
			///this puts the ptr node in front of the current start
			//connect new item to start - Have the new item's pointer, point to start
			ptr->link = start;

			//Assign start a value - Replacing the start of the linked list with the new node's ptr
			start = ptr;
		}

		else
		{
			//"Hook" new item to insertion point's link
			//Assign ptr's link a value - linking to insert ptr
			ptr->link = insertPtr->link;

			//"Hook" insert pointer to new item
			//Assign insertPtr's link a value - link insertPtr and ptr
			insertPtr->link = ptr;
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
//FillList - Reads all the integer values to the end of the input file
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::FillList(ifstream& fin)
{
	//Local variables
	int numbers;
	nodePtr ptr;

	//Primer - read in the first number
	fin >> numbers;

	while (fin)
	{
		//Create a node for the new line of data read
		ptr = CreateANode(numbers);

		//Call the add to list function
		AddToList(ptr);

		//Changer
		fin >> numbers;
	}
}

//----------------------------------------------------------------------------------------------------------------------
//PrintHeaderForOriginalList - Prints the header for the original list
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::PrintHeaderForOriginalList(ofstream& fout)
{
	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

	//Print the centered header
	PrintCenteredMessage(fout, "The original list as it was read in:");

	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

}

//----------------------------------------------------------------------------------------------------------------------
//PrintList - Outputs the node values to an output file with a heading
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::PrintList(ofstream& output)
{
	//Index for formatting 
	int i = 0;

	//Temporary pointer to step through the linked list
	nodePtr tempStart;

	//Determine the message or output list based on the start
	if (IsEmpty())
	{
		//Output a message to the file stream
		output << endl;
		output << setw(27) << ' ' << "There are no items to print" << endl;
	}

	else
	{
		//Assigning tempStart to the start of the linked list
		tempStart = start;

		//Output the first row for the column header
		output << setw(18) << "Digit";
		output << setw(18) << "Digit";
		output << setw(18) << "Digit";
		output << setw(18) << "Digit";
		output << setw(18) << "Digit" << endl;

		//Output the second row for the column header
		output << setw(9) << "number";
		output << setw(9) << "Count";
		output << setw(9) << "number";
		output << setw(9) << "Count";
		output << setw(9) << "number";
		output << setw(9) << "Count";
		output << setw(9) << "number";
		output << setw(9) << "Count";
		output << setw(9) << "number";
		output << setw(9) << "Count" << endl;

		//Print a divider to the output stream
		OutputDivider(output, SYMBOL, WIDTH);

		//While there are items in the list to output
		while (tempStart != NULL)
		{
			//Output the number and digits for the number
			output << right << setw(9) << tempStart->data.number;  
			output << setw(9) << tempStart->data.countOfDigits;

			//Increment i
			i++;

			if (i == 5)
			{
				//Reset i
				i = 0;

				//Output a blank space
				output << endl;
			}

			//Move the pointer to the next item in the list
			tempStart = tempStart->link;
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
//PrintCountOfNumbersInList - Outputs the count of the number in the list
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::PrintCountOfNumbersInList(ofstream& fout, int aNumber)
{
	//Move the pointer down
	fout << endl;

	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

	//Output a label stating the nodes in the list
	fout << "The number of nodes in the list is: " << aNumber << endl;

	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);
}

//----------------------------------------------------------------------------------------------------------------------
//PrintHeaderForNumberInAPosition - Print the header for the PrintNumberInAPosition
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::PrintHeaderForNumberInAPosition(ofstream& fout)
{
	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

	//Print the centered header
	PrintCenteredMessage(fout, "Search & Print Position of Number in list");

	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

}

//----------------------------------------------------------------------------------------------------------------------
//PrintNumberInAPosition - Given a position passed into this method, an output with the number at that position happens
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::PrintNumberInAPosition(ofstream& fout, int position)
{
	//Local variables
	nodePtr temp;

	//Counter starts at the first position of the linked list
	int counter = 0;

	//Set the temp equal to the start
	temp = start;

	//Determine the message or output list based on the start
	if (IsEmpty())
	{
		//Output a message to the file stream
		fout << endl;
		fout << setw(27) << ' ' << "There are no items to print" << endl;
	}

	else
	{
		while (temp != NULL)
		{
			//Increment the counter
			counter++;

			if (counter == position)
			{
				//Output the position and the number associated with that position
				fout << "In the linked list at position " << position << " the number " 
					<< temp->data.number << " was found." << endl;
			}

			else if(temp->link == NULL && position <= 0)
			{
				//Output an error message
				fout << "Position " << position << " does not exist in the list, no number to print" << endl;
			}

			//Move the pointer to the next item in the list
			temp = temp->link;
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
//PrintHeaderForSmallestAndLargest - Print the header for the smallest and largest numbers
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::PrintHeaderForSmallestAndLargest(ofstream& fout)
{
	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

	//Print the centered header
	PrintCenteredMessage(fout, "Smallest & Largest Values");

	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

}

//----------------------------------------------------------------------------------------------------------------------
//FindSmallest - Finds the smallest value in the linked list
//----------------------------------------------------------------------------------------------------------------------
int IntegerClassType::FindSmallest()
{	
	//Local variables
	nodePtr temp;
	int smallest = 999999;

	//Set the temp equal to the start of the list
	temp = start;

	while (temp != NULL)
	{
		if (smallest > temp->data.number)
		{
			//Set the smallest equal to the number
			smallest = temp->data.number;

		}
		//Move to the next pointer
		temp = temp->link;
	}

	return smallest;
}

//----------------------------------------------------------------------------------------------------------------------
//FindLargest - Finds the largest value in the linked list
//----------------------------------------------------------------------------------------------------------------------
int IntegerClassType::FindLargest()
{
	//Local variables
	nodePtr temp;
	int largest = -9999999;

	//Set the temp equal to the start of the list
	temp = start;

	while (temp != NULL)
	{
		if (largest < temp->data.number)
		{
			//Set the smallest equal to the number
			largest = temp->data.number;
		}

		//Move to the next pointer
		temp = temp->link;
	}

	return largest;
}

//----------------------------------------------------------------------------------------------------------------------
//PrintPositionOfNumber - Given a number determine if the number is in the list. Call the smallest and largest functions
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::PrintPositionOfNumber(ofstream& fout, int num)
{
	//Local variables
	nodePtr temp;
	int check = 0;

	//Counter starts at the first position of the linked list
	int counter = 0;

	//Set the temp equal to the start
	temp = start;

	//Determine the message or output list based on the start
	if (IsEmpty())
	{
		//Output a message to the file stream
		fout << endl;
		fout << setw(27) << ' ' << "There are no items to print" << endl;
	}

	else
	{
		while (temp != NULL)
		{
			//Increment the counter
			counter++;

			if (temp->data.number == num)
			{
				//Output the position and the number associated with that position
				fout << "The number  " << num << " was found in position " << counter << endl;

				//Increment the check variable
				check++;
			}

			else if (temp->link == NULL && check == 0)
			{
				//Output an error message
				fout << "The number was not found in the list" << endl;
			}

			//Move to the next pointer
			temp = temp->link;
		}

	}

}

//----------------------------------------------------------------------------------------------------------------------
//FindNumbersInList - Returns the positions and true for the bool flag for the first found occurrence of a number
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::PrintHeaderForFindingNumbersInList(ofstream& fout)
{
	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

	//Print the centered header
	PrintCenteredMessage(fout, "Find Numbers in List");

	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

}

//----------------------------------------------------------------------------------------------------------------------
//FindNumbersInList - Returns the positions and true for the bool flag for the first found occurrence of a number
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::FindNumberInList(int searchNumber, int& position, bool& found)
{
	//Local variables
	nodePtr temp;

	//Counter starts at the first position of the linked list
	int counter = 1;

	//Set the temp equal to the start
	temp = start;

	while (temp != NULL && found == false)
	{
		if (temp->data.number == searchNumber)
		{
			//Set the found value to true
			found = true;

			//Set the position equal to the counter
			position = counter;
		}																										     

		else if (found == false)
		{
			//Increment the counter
			counter++;
		}

		//Move the pointer to the next item in the list
		temp = temp->link;
	}
}

//----------------------------------------------------------------------------------------------------------------------
//PrintHeaderSumAndAverage - Prints the header for the sum and average function
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::PrintHeaderSumAndAverage(ofstream& fout)
{
	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

	//Print the centered header
	PrintCenteredMessage(fout, "Sum & Average of list");

	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

}

//----------------------------------------------------------------------------------------------------------------------
//CalculateSum - Calculates and returns the sum of all numbers in the linked list
//----------------------------------------------------------------------------------------------------------------------
int IntegerClassType::CalculateSum()
{
	//Local variables
	int sum = 0;
	nodePtr temp;

	//Set the temp to the start of the linked list
	temp = start;

	while (temp != NULL)
	{
		//Accumulate the all of the numbers in the linked list
		sum += temp->data.number;

		//Move to the next pointer
		temp = temp->link;
	}

	return sum;

}

//----------------------------------------------------------------------------------------------------------------------
//CalculateAverage - Calculates and returns the average of all numbers in the linked list
//----------------------------------------------------------------------------------------------------------------------
double IntegerClassType::CalculateAverage()
{
	//Local variables
	double average = 0;
	double sum = 0;
	nodePtr temp;

	//Set the temp equal to the start of the function
	temp = start;

	//Call the sum function
	sum = CalculateSum();

	//Calculate the average
	average = sum / countOfNumberList;
	
	return average;
}

//----------------------------------------------------------------------------------------------------------------------
//PrintByDigitCount - Prints the list of numbers from 1 digit to the largest number of digits found in the list
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::PrintByDigitCount(ofstream& fout)
{
	//Local variables
	nodePtr temp;
	int largestDigitCount = 0;
	int numbersInList = 0;

	//Set the temp equal to the start
	temp = start;

	//Set the count of numbers in the list 
	numbersInList = GetCountOfNumbersInList();

	//Set the largest digit count in the list
	largestDigitCount = FindLargestDigitCount();

	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

	//Print the centered header
	PrintCenteredMessage(fout, "Print by Digit Count");

	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

	for (int i = 0; i < largestDigitCount; i++)
	{
		//Print a divider to the output stream
		OutputDivider(fout, SYMBOL, WIDTH);

		fout << setw(25) << "Numbers with " << i + 1 << " Digits" << endl;

		//Print a divider to the output stream
		OutputDivider(fout, SYMBOL, WIDTH);

		for (int i2 = 0; i2 < numbersInList; i2++)
		{
			if (temp->data.countOfDigits == i + 1)
			{
				//Output the number that correlates with the digit section
				fout << setw(16) << temp->data.number << endl;
			}

			//Move to the next pointer
			temp = temp->link;
		}

		//Print a divider to the output stream
		OutputDivider(fout, SYMBOL, WIDTH);
		
		//Set the temp equal to the start
		temp = start;

	}

}

//----------------------------------------------------------------------------------------------------------------------
//PositiveList - Fill the positive list with positive numbers from the list
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::PositiveList(ifstream& fin)
{
	//Local variables
	int numbers;
	nodePtr ptr;

	//Primer - read in the first number
	fin >> numbers;

	while (fin)
	{
		//Create a node for the new line of data read
		ptr = CreateANode(numbers);

		if (numbers > 0)
		{
			//Call the add to list function
			AddToList(ptr);

		}

		//Changer
		fin >> numbers;
	}

}

//----------------------------------------------------------------------------------------------------------------------
//NegativeList - Fill the negative list with negative numbers from the list
//----------------------------------------------------------------------------------------------------------------------
void IntegerClassType::NegativeList(ifstream& fin)
{
	//Local variables
	int numbers;
	nodePtr ptr;

	//Primer - read in the first number
	fin >> numbers;

	while (fin)
	{
		//Create a node for the new line of data read
		ptr = CreateANode(numbers);

		if (numbers < 0)
		{
			//Call the add to list function
			AddToList(ptr);

		}

		//Changer
		fin >> numbers;
	}

}