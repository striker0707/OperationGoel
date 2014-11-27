#ifndef _FOOD_PROGRAM
#define _FOOD_PROGRAM

#include <iostream>
#include <string>
#include <fstream>
#include "SortedList.h"
#include "Food.h"
#include "HashTable.h"
#include "BinarySearchTree.h"

using namespace std;

/** Change what you need to get it to work. Need to have all menu functions implemented */
class FoodProgram
{
private:
	SortedList<Food*> fDB;
	HashTable<string, Food*> fHT;
	BinarySearchTree<Food*> fBST;
public:
	ifstream inputFile;
	ofstream outputFile;
	/** Intializes fDB and fHT */
	FoodProgram();
	/** Parses food file and inputs into fDB */
	/** Saves any changes made to fDB to file */
	~FoodProgram() {}
	void menu();
	/** Accepts option and builds BST from fDB sorted by said option */
	bool buildBST(int option);
	/** Inserts new entries into fDB */
	bool insert();
	/** Removes entries from fDB */
	bool remove();
	bool openinputFile(ifstream &stream);
	bool openoutputFile(ofstream &stream);
	bool Search(string key);


};

#endif;

/* Remember that all food data needs to be stored as dynamic memory in both the BST and HT */
/* "As the records are read, they are placed in dynamic memory and the memory location (address) is then inserted" */

FoodProgram::FoodProgram()
{
	string fname;
	float cal, gfat, chol, sodi, prot;

	bool openinputFile(ifstream &inputFile);
	bool openoutputFile(ofstream &outputFile);

	if (openinputFile(inputFile) == false || openoutputFile(outputFile) == false)       // Checks if both output and input are false
	{
		cout << "Unable to open input file" << endl;                      // If false, prints an error message
		cout << "Ending Program" << endl;
		return;   // Ends Program if the if statement is true
	}      // End if
	else    // When successful opening, program will print sucession
	{
		cout << "Files opened successfully, open output file to see results when program ends" << endl;
	} // end if else

	while (inputFile >> fname >> cal >> gfat >> chol >> sodi >> prot) // Reads file inputs continously until it runs out of inputs
	{
		Food* newFood = new Food(fname, cal, gfat, chol, sodi, prot);
		fDB.insert(newFood);
		fHT.insert(newFood, newFood->getName());
		fBST.insert(newFood);
	}
	fBST.indentedTree();
}


void FoodProgram::menu()
{
	int choice = -1;

	while (choice != 9)
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
		switch (choice)
		{
			case 1:
			{
				this->insert();
				break;
			}
			case 2:
			{
				this->remove();
				break;
			}
			case 3:
			{
				this->Search("Beans");
				break;
			
			}
			 
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
			default:
			{
				cout << "Invalid Option, please enter a valid option (1-9)." << endl;
				system("pause");
				break;
			}
		}

	}
}

bool openinputFile(ifstream &inputFile)
{
	string inputFileName;           // Declares variable for input name

	//cout << "Enter input filename: " << endl;          // Prompts user for input file name
	//getline(cin, inputFileName);                             // Reads input file name

	inputFile.open("Archive.txt");
	/*inputFile.open(inputFileName.c_str());  */                // Opens input file with given name

	if (inputFile.fail())                                   // If the input file fails
	{
		return 0;                                           // End program if input file cannot open
	}
	else
	{
		return 1;                                           // Continues program if input file opens
	}

} // End bool

bool openoutputFile(ofstream &outputFile)
{
	string outputFileName;          // Declares variable for output name

	cout << "Enter output filename: " << endl;         //Prompts user for output file name
	getline(cin, outputFileName);                            // Reads output file name

	outputFile.open(outputFileName.c_str());                // Opens output file with given name

	if (outputFile.fail())                                   // If the output file fails
	{
		return 0;                                           // End program if output file cannot open
	}
	else
	{
		return 1;                                           // Continues program if output file opens
	}

}// End bool

bool FoodProgram::insert()
{
	string iname = "Elton";
	float ical, igf, isod, ipro, ix;
	//cout << "Hellos. pls add in calories, gramsfat, soidum, x, x,xprotei

	Food* insertFood = new Food(iname, 60, 25, 0, 0, 0);
	fBST.insert(insertFood);
	fDB.insert(insertFood);
	fHT.insert(insertFood, insertFood->getName());

	fHT.displayStats();
	fBST.indentedTree();

	return true;
}

bool FoodProgram::remove()
{
	Food removeFood("Waffles");

	fDB.remove(&removeFood);
	fBST.remove(&removeFood);
	fHT.remove("Waffles");

	fHT.displayStats();
	fBST.indentedTree();

	return 1;
}

bool FoodProgram::Search(string key)
{
	Food* fd = new Food();
	if (fHT.contains(key, fd))
	{
		cout << fd;
		return true;
	}

	return false;
}