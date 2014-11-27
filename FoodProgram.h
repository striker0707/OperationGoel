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

template<class ItemType>
void bstPrint(ItemType& item)
{
	cout << *item << endl;
}

class FoodProgram
{
private:
	SortedList<Food*> fDB;
	HashTable<string, Food*> fHT;
	BinarySearchTree<Food*> fBST;
public:
	/** Intializes fDB and fHT */
	FoodProgram();
	/** Parses food file and inputs into fDB */
	/** Saves any changes made to fDB to file */
	~FoodProgram();
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

FoodProgram::FoodProgram()
{
	ifstream inputFile;
	string fname;
	float cal, gfat, chol, sodi, prot;

	bool openinputFile(ifstream &inputFile);

	if (openinputFile(inputFile) == false)       // Checks if both output and input are false
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
		Food* newFood = new Food(fname,fname, cal, gfat, chol, sodi, prot);
		fDB.insert(newFood);
		fHT.insert(newFood, newFood->getName());
		fBST.insert(newFood);
	}
}

FoodProgram::~FoodProgram()
{
	fDB.printToFile("output.txt");
	fDB.clear();
	fBST.clear();
	fHT.clear();
}

void FoodProgram::menu()
{
	int choice = -1;
	string item;

	while (choice != 9)
	{
		cout << endl << "///////////////////////////////////////////////" << endl;
		cout << "     MENU" << endl;
		cout << "1) Add new data" << endl;
		cout << "2) Delete data" << endl;
		cout << "3) Look up nutritional information of food" << endl;
		cout << "4) List data in hash table sequence" << endl;
		cout << "5) List data in key sequence (sorted)" << endl;
		cout << "6) Print indented tree" << endl;
		cout << "7) Effeciency" << endl;
		cout << "8) SECRET MENU OPTION" << endl;
		cout << "9) Quit" << endl;
		cout << "///////////////////////////////////////////////" << endl;
		cout << ": ";

		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				this->insert();
				system("pause");
				break;
			}
			case 2:
			{
				this->remove();
				system("pause");
				break;
			}
			case 3:
			{
				cout << endl << "What food would you like to look up?: ";
				cin >> item;
				this->Search(item);
				system("pause");
				break;
			}
			 
			case 4:
			{
				fHT.print();
				system("pause");
				break;
			}
			case 5:
			{
				cout << endl << "Ordered foods in dictionary";
				cout << endl << "=============================" << endl;
				fBST.inOrder(bstPrint);
				cout << endl;
				system("pause");
				break;
			}
			case 6:
			{
				fBST.indentedTree();
				system("pause");
				break;
			}
			case 7:
			{
				fHT.displayStats();
				system("pause");
				break;
			}
			//case 8:
			//  break;
			case 9: //user quit case
			{
				return;
			}
			default:
			{
				cout << "Invalid Option, please enter a valid option (1-9)." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
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

	//cout << "Enter output filename: " << endl;         //Prompts user for output file name
	//getline(cin, outputFileName);                            // Reads output file name

	/*outputFile.open(outputFileName.c_str());  */              // Opens output file with given name
	outputFile.open("output.txt");

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
	string iName = "Elton";
	float iCal, igFat, iChol, iSod, iPro;
	
	cout << endl << "Please enter information about new food." << endl;
	cout << "Name: ";
	cin >> iName;
	cout << "Calories: ";
	cin >> iCal;
	cout << "Grams Fat: ";
	cin >> igFat;
	cout << "Cholesterol: ";
	cin >> iChol;
	cout << "Sodium: ";
	cin >> iSod;
	cout << "Protein: ";
	cin >> iPro; 

	Food* insertFood = new Food(iName,iName,iCal,igFat,iChol,iSod,iPro);
	
	fBST.insert(insertFood);
	fDB.insert(insertFood);
	fHT.insert(insertFood, insertFood->getName());

	return true;
}

bool FoodProgram::remove()
{
	string iName;
	cout << "Name of food to remove: ";
	cin >> iName;
	Food removeFood(iName);

	fDB.remove(&removeFood);
	fBST.remove(&removeFood);
	fHT.remove(iName);

	return true;
}

bool FoodProgram::Search(string key)
{
	Food* fd = new Food();
	if (fHT.contains(key, fd))
	{
		fd->print(*fd);
		return true;
	}
	else
	{
		cout << "No food with that name found." << endl;
	}
	return false;
}