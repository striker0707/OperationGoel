/** Food database
    Created by Group 3: Elton Vinh, Gordon , Joanne Trinh, Ethan Huang, Loc, */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "FoodProgram.h"

using namespace std;

//function prototypes
void printToOutput(ofstream &outputFile, HashTable<string,Food> hobj); // Need hashtable obj that we will print out our memory to outputfile
void print(char& c)
{
	cout << c << ' ';
}

int main()
{
	
	char choice;
	string fd = "Noodles";
	string fc = "Noodles";

	if (fd == fc)
	{
		cout << "YEAH";
	}

	FoodProgram testrun;
	testrun.menu();
		cout << "HERE " << endl;

	///* BST TEST///////////////////////////*/
	//BinarySearchTree<char> bst;
	//bst.insert('j');
	//bst.insert('f');
	//bst.insert('k');
	//bst.insert('z');
	//bst.insert('a');
	//bst.insert('h');
	//bst.insert('d');
	//cout << bst.size() << endl;
	//bst.indentedTree();
	//bst.breadthfirst(print); cout << endl;
	//bst.inOrder(print); cout << endl;
	//bst.preOrder(print); cout << endl;
	//bst.postOrder(print); cout << endl;
	//bst.clear();
	//cout << bst.indentedTree() << endl;
	//cout << bst.isEmpty() << endl;
	//cout << bst.size() << endl;
	///*///////////////////////////////////*/


	//HashTable<string,string> ht;
	//ht.insert("Elton", "Elton");
	//ht.insert("Gordon", "Gorfon");
	//ht.insert("Joanne", "Joanne");
	//ht.insert("Ethan", "Ethan");
	//ht.insert("Rama", "Rama");
	//ht.insert("Loc", "Loc");
	//ht.displayStats();

	//bool openinputFile(ifstream &inputFile);
	//bool openoutputFile(ofstream &outputFile);
 // 
 //   if (openinputFile(inputFile) == false || openoutputFile(outputFile) == false)       // Checks if both output and input are false
 //   {
 //       cout << "Unable to open input file" << endl;                      // If false, prints an error message
 //       cout << "Ending Program" << endl;
 //       return 1;   // Ends Program if the if statement is true
 //   }      // End if
 //   else    // When successful opening, program will print sucession
 //   {
 //       cout << "Files opened successfully, open output file to see results when program ends" << endl;
 //   } // end if else

 //   while (inputFile >> fname >> cal >> gfat >> chol >> sodi >> prot) // Reads file inputs continously until it runs out of inputs
	//{
	//	Food* newFood = new Food(fname, cal, gfat, chol, sodi, prot);
	//	fDB.insert(newFood);
	//	fHT.insert(newFood);
	//	fBST.insert(newFood);
	//}


    
    //printToOutput(outputFile, hashedTable);
	
    //inputFile.close();      // Closes input file
    //outputFile.close();     // Closes output file

	/** BST ///////////////////////////////////////////////////
	
	node<food> current;
	SortedList<food> foodDB;
	ostream os(foodfile)

	while (!foodfile.eof)
		pull food data into linkedlist

	BinarySearchTree<food> bst;

	current = foodDB.getHead;

	while(not end of linkedlist)
		current.getItem().setSortKey(current.getItem().getAttribute()) //get attribute is whatever we want to sort bst by
		bst.insert(current.getItem())
		current = current->getNext();

	/////////////////////////////////////////////////////////*/

  
    system("pause");//close database
    return 0;
}

//
//bool openinputFile (ifstream &inputFile)
//{
//    string inputFileName;           // Declares variable for input name
//
//    cout << "Enter input filename: " << endl;          // Prompts user for input file name
//    getline(cin,inputFileName);                             // Reads input file name
//
//    inputFile.open(inputFileName.c_str());                  // Opens input file with given name
//
//    if (inputFile.fail())                                   // If the input file fails
//    {
//	return 0;                                           // End program if input file cannot open
//    }
//    else
//    {
//	return 1;                                           // Continues program if input file opens
//    }
//
//} // End bool
//
//bool openoutputFile (ofstream &outputFile)
//{
//    string outputFileName;          // Declares variable for output name
//
//    cout << "Enter output filename: " << endl;         //Prompts user for output file name
//    getline(cin,outputFileName);                            // Reads output file name
//
//    outputFile.open(outputFileName.c_str());                // Opens output file with given name
//
//    if(outputFile.fail())                                   // If the output file fails
//    {
//        return 0;                                           // End program if output file cannot open
//    }
//    else
//    {
//        return 1;                                           // Continues program if output file opens
//    }
//
//}// End bool


//// This function is to print the payment table
//void printToOutput(ofstream &dataFile, HashTable<string,Food> hobj)
//{
//    //This will ultimately depend on how the hashtable is made and used. Will be updated laters
// 	/*dataFile << hobj;*/
//}

