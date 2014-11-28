#ifndef _FOOD_PROGRAM
#define _FOOD_PROGRAM

#include <iostream>
#include <string>
#include <fstream>
#include "SortedList.h"
#include "Food.h"
#include "HashTable.h"
#include "BinarySearchTree.h"
#include <sstream>

using namespace std;

template<class ItemType>
void bstPrint(ItemType& item)
{
	cout << *item << endl;
}

void prnToFile(stringstream& foodPrint, Food& item)
{
	foodPrint << item.getName() << ", ";
	foodPrint << item.getCalories() << ", ";
	foodPrint << item.getGramsFat() << ", ";
	foodPrint << item.getCholesterol() << ", ";
	foodPrint << item.getSodium() << ", ";
	foodPrint << item.getProtein();
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

	string buffer;
	string ssbuffer;
	Food* newFood = new Food();
	Food food;

	//dummy node stuff
	Food* dummy = new Food();
	fBST.insert(dummy);

	if(inputFile.is_open())
	{
		while( getline(inputFile, buffer) )
		{
			stringstream ss(buffer);
  
			getline(ss,ssbuffer, ',');
			food.setName(ssbuffer);
			food.setSortKey(ssbuffer);
			getline(ss,ssbuffer, ',');
			food.setCalories(stof(ssbuffer));
			getline(ss,ssbuffer, ',');
			food.setGramsF(stof(ssbuffer));
			getline(ss,ssbuffer, ',');
			food.setCholesterol(stof(ssbuffer));
			getline(ss,ssbuffer, ',');
			food.setSodium(stof(ssbuffer));
			getline(ss,ssbuffer, ',');
			food.setProtein(stof(ssbuffer));
			

			Food* newFood = new Food();
			*newFood = food;

			fDB.insert(newFood);
			fHT.insert(newFood, newFood->getName());
			fBST.insert(newFood);
		}
	}

}

FoodProgram::~FoodProgram()
{
	cout << endl << "Saving changes..." << endl;
	system("pause");
	fDB.printToFile("Archive.txt", prnToFile);
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
				cin.ignore(); //ignore newline
				getline(cin, item);
				this->Search(item);
				system("pause");
				break;
			}
			 
			case 4:
			{
				cout << endl << "-----------------------------------------------------------------" << endl;
				cout << "Food listed in Hash Sequence";
				cout << endl << "-----------------------------------------------------------------" << endl;
				cout << left << setw(17) << "Name";
				cout << left << setw(9) << "Calories";
				cout << left << setw(11) << "Grams Fat";
				cout << left << setw(12) << "Cholesterol";
				cout << left << setw(9) << "Sodium";
				cout << left << setw(7) << "Protein" << endl << endl;
				fHT.print();
				cout << endl;
				system("pause");
				break;
			}
			case 5:
			{
				cout << endl << "-----------------------------------------------------------------" << endl;
				cout << "Food listed in Alphabetical Order";
				cout << endl << "-----------------------------------------------------------------" << endl;
				cout << left << setw(17) << "Name";
				cout << left << setw(9) << "Calories";
				cout << left << setw(11) << "Grams Fat";
				cout << left << setw(12) << "Cholesterol";
				cout << left << setw(9) << "Sodium";
				cout << left << setw(7) << "Protein" << endl;
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
	cin.ignore(); //ignore newline
	getline(cin, iName);
	
	cout << "Calories: ";
	while(!(cin >> iCal))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}

	cout << "Grams Fat: ";
	while(!(cin >> igFat))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}
	
	cout << "Cholesterol: ";
	while(!(cin >> iChol))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}
	
	cout << "Sodium: ";
	while(!(cin >> iSod))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}
	
	cout << "Protein: ";
	while(!(cin >> iPro))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}
	
	if(iCal < 0 || igFat < 0 || iChol < 0 || iSod < 0 || iPro < 0)
	{
		cout << "Negative values are invalid." << endl;
		return true;
	}

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
	cin.ignore(); //ignore newline
	getline(cin, iName);

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
