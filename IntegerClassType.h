///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Programmer's Name: Parjan Ameen
// File Name:         IntegerClassType.h
// Associated File:   IntegerClassType.cpp                                                                                           
// Header File Contains:
//Contains Gets, Sets, prints, and other functions for the IntegerClassType
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef IntegerClassType_h
#define IntegerClassType_h
//---------------------------------------------------------------------------------------------------------------------
#include "Standards.h"

//Defining a structure nodeType
struct nodeType
{
    //nodeType member variables
    int number;
    int countOfDigits;

};

//Defining a structure node
struct node
{
    //node member variables
    nodeType data;  
    node* link;

};

//Creating a type definition, this is a pointer to the node
typedef node* nodePtr;

//Definition of the class - IntegerClassType
class IntegerClassType 
{

private:
    
    
    //Member variables
    int countOfNumberList;
    nodePtr start;
    
    //Member functions
    void CreateList();
    int SetCountOfDigits(int aNumber);
    nodePtr FindPtrAtEndOfList();
    int FindLargestDigitCount();
    
    
public:
    //Constructor(s)---------------------------------------------------------------------------------------------------
    IntegerClassType(void) {CreateList(); }
    
    //Public member functions
    nodePtr GetStart() const { return start; };
    nodeType GetNodeValue(nodePtr current) const { return current->data; };     
    nodePtr GetNextPointer(nodePtr current) const { return current->link; };
    int GetCountOfNumbersInList();
    nodePtr CreateANode(int aNumber);
    void AddToList(nodePtr ptr);
    bool IsEmpty();
    void FillList(ifstream& fin);
    void PrintList(ofstream& fout);
    void PrintCountOfNumbersInList(ofstream& fout, int aNumber);
    void PrintPositionOfNumber(ofstream& fout, int num);
    int FindSmallest();
    int FindLargest();
    void PrintNumberInAPosition(ofstream& fout, int position);
    void FindNumberInList(int searchNumber, int& position, bool& found);
    int CalculateSum();
    double CalculateAverage();
    void PrintByDigitCount(ofstream& fout);

    //Other functions (added)------------------------------------------------------------------------------------------
    void PrintHeaderForOriginalList(ofstream& fout);
    void PrintHeaderForNumberInAPosition(ofstream& fout);
    void PrintHeaderForSmallestAndLargest(ofstream& fout);
    void PrintHeaderSumAndAverage(ofstream& fout);
    void PrintHeaderForFindingNumbersInList(ofstream& fout);
    void PositiveList(ifstream& fin);
    void NegativeList(ifstream& fin);

    void FreeTheList();

    //Destructor-------------------------------------------------------------------------------------------------------
    ~IntegerClassType(void) {FreeTheList(); }   

    //Setting divider function
    friend void OutputDivider(ofstream& output, char symbolToPrint, int width);

    //Setting print centered message function
    friend void PrintCenteredMessage(ofstream& output, string message);

};

#endif  