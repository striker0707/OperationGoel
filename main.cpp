/** Food database
    Created by Group 3: Elton Vinh, Gordon , Joanne Trinh, Ethan Huang, Loc, */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "HashTable.h"
#include "BinarySearchTree.h"
#include "Food.h"

using namespace std;

//function prototypes
//void writetoOutput(ofstream &stream, HashTable<string,Food> hobj);

//void printToOutput(ofstream &outputFile, Hashtable hashtableobj); // Need hashtable obj that we will print out our memory to outputfile
void menu();

int main()
{
	string fname;
	float cal, gfat, chol, sodi, prot;
    ifstream inputFile;
	ofstream outputFile;
	HashTable<string,Food> hashedTable;
	
	bool openinputFile(ifstream &inputFile);
	bool openoutputFile(ofstream &outputFile);
  
    if (openinputFile(inputFile) == false || openoutputFile(outputFile) == false)       // Checks if both output and input are false
    {
        cout << "Unable to open input file" << endl;                      // If false, prints an error message
        cout << "Ending Program" << endl;
        return 1;   // Ends Program if the if statement is true
    }      // End if
    else    // When successful opening, program will print sucession
    {
        cout << "Files opened successfully, open output file to see results when program ends" << endl;
    } // end if else

    while (inputFile >> fname >> cal >> gfat >> chol >> sodi >> prot) // Reads file inputs continously until it runs out of inputs
	{
		Food newFood = Food(fname, cal, gfat, chol, sodi, prot);
		hashedTable.insert(newFood, fname); //fname can be changed to any other attribute to be placed into hashtable
	}
  
  
  
    menu();
    
    //writetoOutput(outputFile, hashedTable);
	
    inputFile.close();      // Closes input file
    outputFile.close();     // Closes output file


  
    system("pause");//close database
    return 0;
}

void menu()
{
  char choice = -1;
 
  while(choice != 9)
  {
    //menu text is taken directly from the project req
    //recommend we change or lsightly modify some of the names so more "user friendly"ish
    cout << "     MENU" << endl;
    cout << "1) Add new data" << endl;
    cout << "2) Delete data" << endl;
    cout << "3) Find and display one data record using the primary key" << endl; 
    cout << "4) List data in hash table sequence" << endl;
    cout << "5) List data in key sequence (sorted)" << endl;
    cout << "6) Print indented tree" << endl;
    cout << "7) Effeciency" << endl;
    cout << "8) SECRET MENU OPTION" << endl;
    cout << "9) Quit" << endl;
    
    cin >> choice;
    
    //ENTER FUNCTION CALLS FOR EACH MODULE AS WE COMPLETE IT,
    //PLEASE COMMENT OUT YOUR FUNCTION CALL IF YOU COMMIT A CHANGE THAT IS NOT COMPILABLE
    //switch(choice)
    //case 1:
    //  break;
    //case 2:
    //  break;
    //case 3:
    //  break;
    //case 4:
    //  break;
    //case 5:
    //  break;
    //case 6:
    //  break;
    //case 7:
    //  break;
    //case 8:
    //  break;
    //case 9: //user quit case
    //  return 0;
    //  break;
    //default:
    //cout << "Invalid Option, please enter a valid option (1-9)." << endl;
    //system("pause");
    //break;
  }
}

bool openinputFile (ifstream &inputFile)
{
    string inputFileName;           // Declares variable for input name

    cout << "Enter input filename: " << endl;          // Prompts user for input file name
    getline(cin,inputFileName);                             // Reads input file name

    inputFile.open(inputFileName.c_str());                  // Opens input file with given name

    if (inputFile.fail())                                   // If the input file fails
    {
	return 0;                                           // End program if input file cannot open
    }
    else
    {
	return 1;                                           // Continues program if input file opens
    }

} // End bool

bool openoutputFile (ofstream &outputFile)
{
    string outputFileName;          // Declares variable for output name

    cout << "Enter output filename: " << endl;         //Prompts user for output file name
    getline(cin,outputFileName);                            // Reads output file name

    outputFile.open(outputFileName.c_str());                // Opens output file with given name

    if(outputFile.fail())                                   // If the output file fails
    {
        return 0;                                           // End program if output file cannot open
    }
    else
    {
        return 1;                                           // Continues program if output file opens
    }

}// End bool


// This function is to print the payment table
void printToOutput(ofstream &dataFile, HashTable<string,Food> hobj)
{
    //This will ultimately depend on how the hashtable is made and used. Will be updated laters
 	/*dataFile << hobj;*/
}

